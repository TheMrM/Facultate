#include <stdlib.h>
#include <stdio.h>

int binarySearch(int arr[], int left_arr, int right_arr, int x) {

    if (right_arr >= left_arr) {
        int mijloc = left_arr + (right_arr - left_arr) / 2;
        if (arr[mijloc] == x) {
            return mijloc;
        }
        if (arr[mijloc] > x) {
            return binarySearch(arr, left_arr, mijloc - 1, x);
                }
        return binarySearch(arr, mijloc + 1, right_arr, x);
    }
    return -1;
    }

int main() {

    int arr[] = {2, 5, 6, 8, 9, 10, 20, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    int result = binarySearch(arr, 0 , n - 1, x);
    (result == -1) ? printf("Element not in arr\n") :
                     printf("Element is present in the arr at index \n %d", result);

    return 0;
}
