#include <iostream>
#include <vector>
#include <algorithm>

class CountingSort {
public:
    static void counting(std::vector<int>& arr) {
        int max_element = *std::max_element(arr.begin(), arr.end());
        int min_element = *std::min_element(arr.begin(), arr.end());

        int range = max_element - min_element + 1;
        std::vector<int> count(range, 0);
        std::vector<int> output(arr.size());

        for (int i : arr) {
            count[i - min_element]++;
        }

        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[arr[i] - min_element] - 1] = arr[i];
            count[arr[i] - min_element]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }
};

int main() {
    std::vector<int> arr = {28, 10, 2, 8, 38, 59, 11, 29, 48, 85};

    std::cout << "Unsorted array: " << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }

    CountingSort::counting(arr);

    std::cout << "\nSorted array: " << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}