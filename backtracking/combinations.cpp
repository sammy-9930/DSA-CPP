class Solution {
public:
    void helper(int n, int k, int idx, vector<int>& cur, vector<vector<int>>& res){
        if (cur.size() == k){
            res.push_back(cur);
            return;
        }

        if (idx > n) return; 

        cur.push_back(idx);
        helper(n, k, idx+1, cur, res);
        cur.pop_back(); 

        helper(n, k, idx+1, cur, res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(n, k, 1, cur, res);
        return res;
    }
};

