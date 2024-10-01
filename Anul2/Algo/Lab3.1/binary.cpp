#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
    public:
        static int binary(const vector<int>& arr, int target) {
            int left = 0;
            int right = arr.size() - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (arr[mid] == target) {
                    return mid;
                }

                if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid + 1;
                }
            }

            return -1;
        }
};

int main() {
    vector<int> arr = {1,4,8,11,19,20,21,29,39,40};
    int target = 29;

    cout << "Array for searching "<< target << endl;
    for (int num : arr) {
        cout << num << " ";
    }

    int result = BinarySearch::binary(arr, target);

    if (result != 1) {
        cout << "\nElment found at index "<< result << "." << endl;
    } else {
        cout << "\nElement not found." << endl;
    }

    return 0;
}