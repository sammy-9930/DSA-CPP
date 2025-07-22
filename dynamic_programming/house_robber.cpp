// Time limit exceeded 
class Solution {
public:
    int helper(vector<int>& nums, int idx){
        if (idx >= nums.size())
            return 0;
          
        // rob 
        int rob = nums[idx] + helper(nums, idx+2);

        // don't rob 
        int dont_rob = helper(nums, idx+1);  

        return max(rob, dont_rob); 

    }

    int rob(vector<int>& nums) {
        int max_amount;
        return helper(nums, 0);
    }
};

// optimized - using dynamic programming 

class Solution {
public:
    int helper(int& max_amount, vector<int>& nums, int idx, vector<int>& dp){
        // base cond 
        if (idx >= nums.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx]; 

        // rob 
        int rob = nums[idx] + helper(max_amount, nums, idx+2, dp);

        // don't rob 
        int dont_rob = helper(max_amount, nums, idx+1, dp);

        // max 
        max_amount = max(rob, dont_rob);
        dp[idx] = max_amount;
        return max_amount;
    }
    int rob(vector<int>& nums) {
        int max_amount = 0;
        vector<int> dp(nums.size(), -1);
        helper(max_amount, nums, 0, dp);
        return max_amount;
    }
};