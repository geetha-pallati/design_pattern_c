#include <stdio.h>

// Forward declaration of the Context
struct LightSwitch;

typedef struct State {
    void (*onPress)(struct LightSwitch* context);
} State;

// Forward declaration of the ON state
typedef struct LightSwitch {
    State* currentState;
} LightSwitch;

void pressButton(LightSwitch* ls) {
    ls->currentState->onPress(ls);
}
extern State OnState;

void offPress(LightSwitch* ls) {
    printf("Turning light ON...\n");
    ls->currentState = &OnState; // Transition to ON
}

State OffState = { offPress };
void onPress(LightSwitch* ls) {
    printf("Turning light OFF...\n");
    ls->currentState = &OffState; // Transition to OFF
}

State OnState = { onPress };
int main() {
    LightSwitch myLight;
    myLight.currentState = &OffState; // Initial state

    // The same function call results in different behavior!
    pressButton(&myLight); // Output: Turning light ON...
    pressButton(&myLight); // Output: Turning light OFF...
    pressButton(&myLight); // Output: Turning light ON...

    return 0;
}