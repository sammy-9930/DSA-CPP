#include <vector>
#include <limits.h>

using namespace std;

/*
sliding window 
time: O(n), space: O(1)
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_subarray = INT_MAX;
        int l = 0;
        int cur_sum = 0;
        for (int r = 0; r < nums.size(); r++){
            cur_sum += nums[r];
            while (cur_sum >= target){
                min_subarray = min(min_subarray, r - l + 1);
                cur_sum -= nums[l];
                l += 1;
            }
        }
        return min_subarray == INT_MAX ? 0 : min_subarray;
    }
};