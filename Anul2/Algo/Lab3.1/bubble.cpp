#include <iostream>
#include <vector>

class BubbleSort {
    public:
        static void bubble(std::vector<int>& arr) {
            int n = arr.size();
            bool swapped;
            for (int i = 0; i < n-1; i++){
                swapped = false;
                for (int j = 0; j < n-1; j++) {
                    if (arr[j] > arr[j +1]) {
                        std::swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
                if(!swapped) {
                    break;
                }
            }
        }
};

int main(){
    std::vector<int> arr = {22, 21, 24, 25, 27, 20};

    std::cout<<"Pentru sirul nesortat: "<<std::endl;
    for(int num : arr) {
        std::cout<<num<<" ";
    }
    BubbleSort::bubble(arr);

    std::cout<<"\nSirul sortat este: "<<std::endl;
    for(int num : arr) {
        std::cout<<num<<" ";
    }

    return 0;
}