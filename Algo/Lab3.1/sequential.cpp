#include <iostream>
#include <vector>

class SequentialSort {
public:
    static int sequential(const std::vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::vector<int> arr = {64, 18, 29, 100, 109, 20, 49, 38, 84, 61};
    int target = 100; // Change this to the element you want to search for

    std::cout << "Array for searching: "<< target << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }

    int result = SequentialSort::sequential(arr, target);

    if (result != -1) {
        std::cout << "\nElement found at index " << result << std::endl;
    } else {
        std::cout << "\nElement not found." << std::endl;
    }

    return 0;
}
