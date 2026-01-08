#include<stdio.h>
#include<stdlib.h>  
#include<string.h>

// Observer structure definition, interface for observers to implement
typedef struct Observer {
    void (*update)(int new_value);
} Observer;

#define MAX_OBSERVERS 10

// Subject structure definition, maintains a list of observers
typedef struct Subject {
    Observer* observers[MAX_OBSERVERS];
    int observer_count;
    int state;
} Subject;
// Function to initialize the subject
void init_subject(Subject* subject) {
    subject->observer_count = 0;
    subject->state = 0;
}
// Function to register an observer
void register_observer(Subject* subject, Observer* observer) {
    if (subject->observer_count < MAX_OBSERVERS) {
        subject->observers[subject->observer_count++] = observer;
    }
}
// Function to notify all registered observers of a state change
void notify_observers(Subject* subject) {
    for (int i = 0; i < subject->observer_count; i++) {
        subject->observers[i]->update(subject->state);
    }
}
// Function to set the state of the subject and notify observers
void set_state(Subject* subject, int new_value) {
    subject->state = new_value;
    printf("Subject state changed to: %d\n", new_value);
    notify_observers(subject);
}
// Concrete observer implementation
typedef struct ConcreteObserver {
    Observer base;      
    const char* name;
} ConcreteObserver;
// Update function for the concrete observer
void concrete_observer_update(int new_value) {
    printf("Observer notified with new value: %d\n", new_value);
}

int main() {
    Subject subject; // Create a subject
    init_subject(&subject);    // Initialize the subject  
    ConcreteObserver observer1; // Create a concrete observer
    observer1.base.update = concrete_observer_update; // Set the update function
    observer1.name = "Observer1"; // Set the observer name
    register_observer(&subject, (Observer*)&observer1); // Register the observer with the subject
    set_state(&subject, 42); // Change state and notify observers
    set_state(&subject, 100); // Change state and notify observers
    return 0;
}