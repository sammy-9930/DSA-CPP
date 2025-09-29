#include <vector>
#include <limits.h>

using namespace std;

/*
Brute force
time: O(n^2)
space: O(1)
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        for(int l = 0; l < nums.size(); l++){
            int curSum = 0;
            for(int r = l; r < nums.size(); r++){
                curSum += nums[r];
                if (curSum >= target){
                    minLen = min(minLen, r - l + 1);
                    break;
                }
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;       
    }
};

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