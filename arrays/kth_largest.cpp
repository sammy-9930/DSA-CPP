#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // creates a max heap by default 
        std::make_heap(nums.begin(), nums.end());
        for(int i = 0; i < k-1; i++){
            std::pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        std::pop_heap(nums.begin(), nums.end());
        int result = nums.back();
        return result;
    }
};