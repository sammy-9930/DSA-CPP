/*
Backtracking - don't pick , pick 
time complexity: O(n * 2^n) - subsets + copy 
space complexity: O(n) 
*/
class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int> cur, int idx){
        if(idx == nums.size()){
            res.push_back(cur);
            return;
        }

        helper(nums, res, cur, idx+1);

        cur.push_back(nums[idx]);
        helper(nums, res, cur, idx+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(nums, res, cur, 0);
        return res;
    }
};

/*
Backtracking - pick, don't pick 
time complexity: O(n * 2^n) - subsets + copy 
space complexity: O(n) 
*/
class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int> cur, int idx){
        if(idx == nums.size()){
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[idx]);
        helper(nums, res, cur, idx+1);
        cur.pop_back();

        helper(nums, res, cur, idx+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(nums, res, cur, 0);
        return res;
    }
};

/*
Backtracking - passing cur by reference - pick, don't pick
time complexity: O(n * 2^n) - subsets + copy 
space complexity: O(n) 
*/
class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int idx){
        if(idx == nums.size()){
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[idx]);
        helper(nums, res, cur, idx+1);
        cur.pop_back();

        helper(nums, res, cur, idx+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(nums, res, cur, 0);
        return res;
    }
};

/*
Backtracking - passing cur by reference - don't pick, pick
time complexity: O(n * 2^n) - subsets + copy 
space complexity: O(n) 
*/
class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int idx){
        if(idx == nums.size()){
            res.push_back(cur);
            return;
        }

        helper(nums, res, cur, idx+1);

        cur.push_back(nums[idx]);
        helper(nums, res, cur, idx+1);
        cur.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(nums, res, cur, 0);
        return res;
    }
};
