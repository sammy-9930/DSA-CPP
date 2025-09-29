/* With memoization */
class Solution {
public:
    int helper(int n, vector<int>& res){
        if (res[n] != -1){
            return res[n];
        }
        if (n <= 2){
            return n;
        }
        return res[n] = helper(n-1, res) + helper(n-2, res);
    }
    int climbStairs(int n) {
        vector<int> res(n + 1, -1);
        return helper(n, res);
    }
};