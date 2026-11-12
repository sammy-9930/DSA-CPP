/*
Time : O(2^n)
Space : O(n)
*/
class Solution {
public:
    void helper(int n, vector<string>& res, string cur, int n_open, int n_close){
        if(n_open + n_close == (n*2)){
            res.push_back(cur);
            return;
        }

        if(n_open < n){
            helper(n, res, cur + "(", n_open+1, n_close);
        }

        if(n_open > n_close){
            helper(n, res, cur + ")", n_open, n_close+1);
        }      
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, res, "", 0, 0);
        return res;
    }
};
