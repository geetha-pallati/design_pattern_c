#include<stdio.h>

typedef void (*StrategyFunc)(int* arr, int size);

void bubble_sort_array(int* arr, int size) {
    // Default strategy: Bubble Sort
    for (int i = 0; i < size - 1; i++) { // Traverse through all array elements 
        for (int j = 0; j < size - i - 1; j++) { // Last i elements are already in place
            if (arr[j] > arr[j + 1]) { // Swap if the element found is greater than the next element
                int temp = arr[j];  // move larger element to the right
                arr[j] = arr[j + 1]; // move smaller element to the left
                arr[j + 1] = temp; // swap complete
            }
            // After each inner loop iteration,
            //  the largest unsorted element bubbles up to its correct position.
        }
        // After each outer loop iteration,
        // the next largest element is placed in its correct position.
    }
    // The process continues until the entire array is sorted.
}
void selection_sort_array(int* arr, int size) {
    // Alternative strategy: Selection Sort
    for (int i = 0; i < size - 1; i++) { // Traverse through all array elements
        int min_idx = i; // Assume the minimum is the first element of unsorted array
        for (int j = i + 1; j < size; j++)  { // Find the minimum element in unsorted array
            if (arr[j] < arr[min_idx]) { // Update min_idx if the current element is smaller
                min_idx = j; // Update index of minimum element
            }
            // After each inner loop iteration, 
            // the index of the minimum element in the unsorted portion is identified.
        }
        int temp = arr[i]; // Swap the found minimum element with the first element of unsorted array
        arr[i] = arr[min_idx]; // Place minimum element at the beginning of unsorted array
        arr[min_idx] = temp; // Swap complete.
        // After each outer loop iteration,
        // the smallest unsorted element is placed in its correct position. 
    }
}
void insertion_sort_array(int* arr, int size) {
    // Alternative strategy: Insertion Sort
    for (int i = 1; i < size; i++) { // Start from the second element
        int key = arr[i];  // Current element to be inserted
        int j = i - 1;  // Index of the last sorted element i = 1, j = 0
        while (j >= 0 && arr[j] > key) { // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
            arr[j + 1] = arr[j];  // Shift element to the right
            j--; // Move to the previous element
        }
        arr[j + 1] = key; // Insert the key at its correct position
        // After each outer loop iteration, the subarray arr[0..i] is sorted.
        // The process continues until the entire array is sorted. 
    }
}
void quick_sort_array(int* arr, int size) {
    // Alternative strategy: Quick Sort
    if (size < 2) return; // Base case: arrays with 0 or 1 element are already sorted

    int pivot = arr[size / 2]; // Choose pivot 
    int i, j;  // Index variables
    for (i = 0, j = size - 1;; i++, j--) { // Partitioning step
        while (arr[i] < pivot) i++;  // Move i to the right until an element >= pivot is found
        while (arr[j] > pivot) j--;  // Move j to the left until an element <= pivot is found
        if (i >= j) break; // If indices cross, partitioning is done
        int temp = arr[i]; // Swap elements at i and j , to place them in correct partition
        arr[i] = arr[j]; // Swap elements at i and j
        arr[j] = temp; // Swap elements at i and j . for next iteration
    }
    quick_sort_array(arr, i); // Recursively sort the left partition
    quick_sort_array(arr + i, size - i); // Recursively sort the right partition
}

typedef struct {
    StrategyFunc strategy; // Function pointer to the current strategy.
} StrategyContext; // Context holding the current strategy.

void set_strategy(StrategyContext* context, StrategyFunc strategy) {
    context->strategy = strategy;       // Set or change the strategy. starategy points to function for sorting. 
}
void execute_strategy(StrategyContext* context, int* arr, int size) {
    if (context->strategy) {          // Check if a strategy is set.
        context->strategy(arr, size); // Execute the current strategy.
    } else {
        printf("No strategy set.\n");
    }
}   

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    StrategyContext context; // Create a context for strategy pattern.
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Input array: ");
    print_array(arr1, size1);


    set_strategy(&context, bubble_sort_array); // Set initial strategy to Bubble Sort
    execute_strategy(&context, arr1, size1); // Execute sorting using the current strategy
    printf("Sorted array using Bubble Sort: \n");
    print_array(arr1, size1);

    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    set_strategy(&context, selection_sort_array); // Change strategy to Selection Sort 
    execute_strategy(&context, arr2, size2); // Execute sorting using the new strategy
    printf("Sorted array using Selection Sort: \n");
    print_array(arr2, size2);

    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    set_strategy(&context, insertion_sort_array); // Change strategy to Insertion Sort
    execute_strategy(&context, arr3, size3); // Execute sorting using the new strategy
    printf("Sorted array using Insertion Sort: \n");
    print_array(arr3, size3);

    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);

    set_strategy(&context, quick_sort_array); // Change strategy to Quick Sort
    execute_strategy(&context, arr4, size4); // Execute sorting using the new strategy
    printf("Sorted array using Quick Sort: \n");
    print_array(arr4, size4);

    return 0;
}
#if 0
typedef void (*StrategyFunc)(int, int);

void add(int a, int b) {
    printf("Addition: %d\n", a + b);
}   
void subtract(int a, int b) {
    printf("Subtraction: %d\n", a - b);
}
void multiply(int a, int b) {
    printf("Multiplication: %d\n", a * b);
}
typedef struct {
    StrategyFunc strategy;
} StrategyContext;

void set_strategy(StrategyContext* context, StrategyFunc strategy) {
    context->strategy = strategy;
}
void execute_strategy(StrategyContext* context, int a, int b) {
    if (context->strategy) {
        context->strategy(a, b);
    } else {
        printf("No strategy set.\n");
    }
}
int main() {
    StrategyContext context;    
    set_strategy(&context, add);
    execute_strategy(&context, 5, 3);
    set_strategy(&context, subtract);
    execute_strategy(&context, 5, 3);
    set_strategy(&context, multiply);
    execute_strategy(&context, 5, 3);
    return 0;
}
#endif