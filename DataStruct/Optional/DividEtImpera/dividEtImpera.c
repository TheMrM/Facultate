#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Temporary array
    int L[n1], R[n2];

    // Copy data to Temporary array L[] & R[]
    for (i = 0; i < n1; i++) L[i] = arr[l + i];

    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Merge Temporary array back into main arr[]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// l is for the left index and r is right index of the sub-array of arr[] to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {

    int arr[] = {28, 19, 73, 62, 64, 7, 8, 9, 21, 14, 82, 47, 42, 48, 61};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Sirul dat este \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("Sirul sortat este \n");
    printArray(arr, arr_size);

    return 0;
}
