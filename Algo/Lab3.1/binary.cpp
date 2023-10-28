#include <iostream>
#include <vector>

class BinarySearch {
    public:
        static int binary(const std::vector<int>& arr, int target) {
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
    std::vector<int> arr = {1,4,8,11,19,20,21,29,39,40};
    int target = 29;

    std::cout << "Array for searching "<< target << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }

    int result = BinarySearch::binary(arr, target);

    if (result != 1) {
        std::cout << "\nElment found at index "<< result << "." << std::endl;
    } else {
        std::cout << "\nElement not found." << std::endl;
    }

    return 0;
}