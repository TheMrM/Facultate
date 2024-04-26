#include <stdio.h>

void merge(int array[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Temp Array
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) L[i] = array[left + i];
    for (j = 0; j < n2; j++) R[j] = array[middle + 1 + j];

    // Merge the temp arrays back into array[left...right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Main function that sorts an array using merge()
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        // Find middle point
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Merge the sorted halves
        merge(array, left, middle, right);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {

    int array[] = {28, 8, 1, 2, 9, 29, 83, 38, 74, 62, 56};
    int array_size = sizeof(array) / sizeof(array[0]);
    printf("Arrayul initial este:\n");
    printArray(array, array_size);

    mergeSort(array, 0, array_size - 1);

    printf("\nArrayul sortat este:\n");
    printArray(array, array_size);

return 0;
}
