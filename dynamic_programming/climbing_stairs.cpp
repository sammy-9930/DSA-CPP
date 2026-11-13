class Solution {
public:
    int helper(int n, int idx){
        if(idx >= n)
            return 0;
        
        if(idx == n-1)
            return 1;
        
        if(idx == n-2)
            return 2;

        return helper(n, idx+1) + helper(n, idx+2);
    }
    int climbStairs(int n) {
        return helper(n, 0);
    }
};



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
