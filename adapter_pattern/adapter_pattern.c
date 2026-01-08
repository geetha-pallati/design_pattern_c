#include <stdio.h>

// Our modern system expects sensors to give readings in Celsius
typedef struct TemperatureSensor {
    float (*getTemperatureC)();
} TemperatureSensor;


float legacy_get_fahrenheit() {
    return 98.6f; // Static example value
}

// The conversion logic
float adapter_logic() {
    float f = legacy_get_fahrenheit();
    float c = (f - 32.0f) * 5.0f / 9.0f;
    return c;
}

// Function to "plug in" the legacy system to the new interface
void setup_adapter(TemperatureSensor* sensor) {
    sensor->getTemperatureC = &adapter_logic;
}

int main() {
    TemperatureSensor mySensor;
    
    // Connect the legacy system via the adapter
    setup_adapter(&mySensor);

    // The client uses the modern interface
    float currentTemp = mySensor.getTemperatureC();
    
    printf("Current Temperature: %.2f C\n", currentTemp); // Output: 37.00 C
    
    return 0;
}
