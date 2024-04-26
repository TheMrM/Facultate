#include <stdlib.h>

// Function for changeing two elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function that chooses a pivot and moves all the lower elements to its left and bigger elements to its right
int partition(int array[], int low, int high) {
    int pivot = array[high];
    // Index of lowest element
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // If current element is lower or equal with pivot
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// Main function that implements QuickSort
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // pi is partition index, array[pi] is at its place
        int pi = partition(array, low, high);

        // We sort elements before partitioning, separatly
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Function to show an array of size N
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {28, 71, 39, 1, 7, 8, 9, 99, 88, 33, 22, 54};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Arrayul initial\n");
    printArray(array, n);

    quickSort(array, 0, n - 1);

    printf("Sorted array:\n");
    printArray(array, n);

    return 0;
}
