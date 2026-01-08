#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int data;
} Singleton;

static Singleton* instance = NULL;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   

Singleton* get_instance() {
    if (instance == NULL) {
        pthread_mutex_lock(&mutex);
        if (instance == NULL) {
            instance = (Singleton*)malloc(sizeof(Singleton));
            instance->data = 42; // Example initialization
        }
        pthread_mutex_unlock(&mutex);
    }
    return instance;
}

int main() {
    Singleton* singleton1 = get_instance();
    Singleton* singleton2 = get_instance();

    printf("Singleton Data: %d\n", singleton1->data);
    printf("Are both instances the same? %s\n", (singleton1 == singleton2) ? "Yes" : "No");

    // Clean up
    free(instance);
    return 0;
}