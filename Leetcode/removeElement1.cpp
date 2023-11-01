#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int n = nums.size();
        int index = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                if (i != index) {
                    nums[index] = nums[i];
                }
                index++;
            }
        }

        return index;
    }
};
