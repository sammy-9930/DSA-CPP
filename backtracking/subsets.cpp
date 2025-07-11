class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int> cur, int ind, vector<int>& nums){
        if (ind == nums.size()){
            res.push_back(cur);
            return;
        }
        // pick
        cur.push_back(nums[ind]);
        helper(res, cur, ind+1, nums);
        cur.pop_back();

        // don't pick 
        helper(res, cur, ind+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(res, cur, 0, nums);
        return res;
    }
};