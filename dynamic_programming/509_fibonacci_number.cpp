/*
Recursion
Time complexity : O(2^n)
Space complexity : O(n) - recursive stack space
*/
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        return fib(n-1) + fib(n-2);
    }
};

/*
Recursion with memoization
Time complexity : O(n) 
Space complexity : O(n) 
*/
class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n == 1 || n == 0)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};

/*
Tabulation - iterative 
Time complexity : O(n)
Space complexity : O(n) - for array
*/
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

/*
Space optimized - iterative
Time complexity : O(n)
Space complexity : O(1)
*/
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int num1 = 0, num2 = 1;
        int num3;
        for(int i=2; i <= n; i++){
            num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
        }
        return num3;
    }
};
