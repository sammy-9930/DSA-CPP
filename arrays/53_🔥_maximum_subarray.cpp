/*
Brute force 
Time complexity: O(n^2)
Space complexity: O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        for(int i = 0; i < nums.size(); i++){
            int cur = 0;
            for(int j = i; j < nums.size(); j++){
                cur += nums[j];
                max_sum = max(max_sum, cur);
            }
        }
        return max_sum;
    }
};

/*
Kadane's Algorithm
if the running sum becomes negative, keeping it will only reduce the sum of any future subarray
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int maxSum = INT_MIN;
        int curSum = 0;
        for(int number : nums){
            curSum += number;
            maxSum = max(curSum, maxSum);
            if(curSum < 0){
                curSum = 0;
            }
        }
        return maxSum;
    }
};
