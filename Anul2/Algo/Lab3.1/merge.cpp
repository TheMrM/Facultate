#include <iostream>
#include <vector>

class MergeSort {
    public:
        static void merge(std::vector<int>& arr) {
            if (arr.size() > 1) {
                int mid = arr.size() / 2;
                std::vector<int> left(arr.begin(), arr.begin() + mid);
                std::vector<int> right(arr.begin() + mid, arr.end());

                merge(left);
                merge(right);

                int i = 0, j = 0, k = 0;

                while (i < left.size() && j < right.size())
                {
                    if(left[i] < right[j]) {
                        arr[k] = left[i];
                        i++;
                    } else {
                        arr[k] = right[j];
                        j++;
                    }
                    k++;
                }
                
                while (i < left.size()) {
                    arr[k] = left[i];
                    i++;
                    k++;
                }

                while (j < right.size()) {
                    arr[k] = right[j];
                    j++;
                    k++;
                }
            }
        }
};

int main() {
    std::vector<int> arr = {28,10,93,38,27,64,36,47};

    std::cout << "Unsorted array: " << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }

    MergeSort::merge(arr);

    std::cout << "\nSorted array: " << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}