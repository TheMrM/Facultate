#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int* a, int* b);
int binarySearch(int arr[], int left, int righti, int x);
void printArray(int arr[], int size);
int readArrayFromFile(const char* filename, int** arr);

int main() {
    int* arr;
    int n = readArrayFromFile("vector.in", &arr);

    if (n > 0) {
        printf("Arrayul citit: ");
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");

        quickSort(arr, 0, n - 1);

        printArray(arr, n);

        int x = 83;
        int result = binarySearch(arr, 0, n - 1, x);
        if (result != -1) printf("Elementul %d gasit la indexul: %d\n", x, result);
        else printf("Elementul nu a fost gasit\n");

        free(arr);
    } else {
        printf("Nu sa putut citi fisierul sau fisierul e gol.\n");
    }

    return 0;
}

int readArrayFromFile(const char* filename, int** arr) {
    FILE* file = fopen(filename, "r");
    if (!file) return -1;

    int size = 0, capacity = 10;
    *arr = (int*)malloc(capacity * sizeof(int));
    if (!*arr) return -1;

    while (fscanf(file, "%d", &(*arr)[size]) != EOF) {
        size++;
        if (size == capacity) {
            capacity *= 2;
            *arr = (int*)realloc(*arr, capacity * sizeof(int));
            if (!*arr) return -1;
        }
    }

    fclose(file);
    return size;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);

        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == x) return middle;
        if (arr[middle] > x) return binarySearch(arr, left, middle - 1, x);
        return binarySearch(arr, middle + 1, right, x);
    }
    return -1;
}

void printArray(int arr[], int size) {
    printf("Arrayul sortat: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}
