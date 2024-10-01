#include <iostream>
#include <vector>

class InvertionSort {
    public:
        static void invertion(std::vector<int>& arr) {
            int n = arr.size();
            for (int i = 1; i < n; i++) {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key; 
            }
        }
};

int main(){
    std::vector<int> arr = {28,19,40,20,10,9,1,2,3};

    std::cout<<"Pentru sirul nesortat: "<< std::endl;
    for(int num : arr) {
        std::cout << num << " ";
    }

    InvertionSort::invertion(arr);

    std::cout<<"\nSirul sortat este: "<< std::endl;
    for(int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}