// 0 to n 
class Solution {
public:
    void helper(vector<int>& candidates,  int target, vector<vector<int>>& res, vector<int> cur, int idx){
        if (target == 0){
            res.push_back(cur);
            return;
        }
        
        if (idx >= candidates.size() || target < 0){
            return;
        }

        // pick 
        cur.push_back(candidates[idx]);
        // The same number may be chosen from candidates an unlimited number of times
        helper(candidates, target - candidates[idx], res, cur, idx);
        cur.pop_back();

        // dont pick 
        helper(candidates, target, res, cur, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(candidates, target, res, cur, 0);
        return res;
    }
};

// n to 0
class Solution {
public:
    void helper(vector<int>& candidates,  int target, vector<vector<int>>& res, vector<int> cur, int idx){
        if (target == 0){
            res.push_back(cur);
            return;
        }
        
        if (idx < 0 || target < 0){
            return;
        }

        // pick 
        cur.push_back(candidates[idx]);
        // The same number may be chosen from candidates an unlimited number of times
        helper(candidates, target - candidates[idx], res, cur, idx);
        cur.pop_back();

        // dont pick 
        helper(candidates, target, res, cur, idx-1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(candidates, target, res, cur, candidates.size()-1);
        return res;
    }
};