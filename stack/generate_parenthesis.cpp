class Solution {
private:
    void validParenthesis(int n_open, int n_close, string curStr, vector<string>& res, int n){
        if (curStr.size() == 2*n){
            res.push_back(curStr);
            return;
        }
        if (n_open < n){
            validParenthesis(n_open + 1, n_close, curStr + "(", res, n);
        }
        if (n_close < n_open){
            validParenthesis(n_open, n_close+1, curStr + ")", res, n);
        }   
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        validParenthesis(0, 0, "", res, n); 
        return res; 
    }
};
