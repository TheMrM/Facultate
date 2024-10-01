#include <iostream>
#include <vector>

class SelectionSort {
    public:
        static void selection(std::vector<int>& arr) {
            int n = arr.size();
            for (int i = 0; i < n -1; i++) {
                int min_index = i;
                for (int j = i + 1; j < n; j++) {
                    if (arr[j] < arr[min_index]) {
                        min_index = j;
                    }
                }
                if (min_index !=i) {
                    std::swap(arr[i], arr[min_index]);
                }
            }
        }
};

int main(){
    std::vector<int> arr = {11, 29, 12, 5, 9, 20};

    std::cout<<"Pentru sirul nesortat: " << std::endl;
    for(int num : arr) {
        std::cout << num << " ";
    }

    SelectionSort::selection(arr);

    std::cout<<"\nSirul sortat este: " << std::endl;
    for(int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}