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
    int helper(vector<int>& nums, vector<int>& count, int idx){
        if (idx >= nums.size()){
            return 0;
        }

        if (count[idx] != -1){
            return count[idx];
        }
        
        int rob = nums[idx] + helper(nums, count, idx + 2);
        int dontRob = helper(nums, count, idx + 1);
        count[idx] = max(rob, dontRob);
        return count[idx];
    }

    int rob(vector<int>& nums) {
        vector<int> count(nums.size(), -1);
        return helper(nums, count, 0);
    }
};