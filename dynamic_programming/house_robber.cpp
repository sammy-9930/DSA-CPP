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