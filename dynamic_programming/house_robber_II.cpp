/*
Recursive solution 
Time complexity: O(2^n)
Space complexity: O(n) for recursion stack 
*/
class Solution {
public:
    int helper(vector<int>& nums, int idx, int max_limit){
        if (idx > max_limit)
            return 0; 
        
        // rob 
        int rob = nums[idx] + helper(nums, idx+2, max_limit);

        // don't rob 
        int dont_rob = helper(nums, idx+1, max_limit);

        return max(rob, dont_rob);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        // include first house 
        int inc = helper(nums, 0, nums.size()-2);
        // don't include first house 
        int dont_inc = helper(nums, 1, nums.size()-1);
        return max(inc, dont_inc);                                                                 
    }
};

/*
Memoization solution 
Time complexity: O(n)
Space complexity: O(n) for recursion stack + O(n) for dp array
*/
class Solution {
public:
    int helper(vector<int>& nums, int idx, int max_limit, vector<int>& arr){
        // base condition 
        if (idx > max_limit)
            return 0; 
        
        // memoization 
        if (arr[idx] != -1)
            return arr[idx];
        
        // rob 
        int rob = nums[idx] + helper(nums, idx+2, max_limit, arr);

        // don't rob 
        int dont_rob = helper(nums, idx+1, max_limit, arr);

        return arr[idx] = max(rob, dont_rob);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> arr1(nums.size(), -1);
        // include first house 
        int inc = helper(nums, 0, nums.size()-2, arr1);
        // don't include first house 
        vector<int> arr2(nums.size(), -1);
        int dont_inc = helper(nums, 1, nums.size()-1, arr2);
        return max(inc, dont_inc);                                                                 
    }
};