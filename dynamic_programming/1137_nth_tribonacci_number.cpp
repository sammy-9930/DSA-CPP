/*
Recursion
time complexity : O(2^n)
space complexity : O(n) - recursive stack space 
*/
class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1)
            return n;
        if (n == 2)
            return 1;
        return tribonacci(n-1) + tribonacci(n-2)+ tribonacci(n-3);
    }
};

/*
Recursion with memoization
Time complexity : O(n) 
Space complexity : O(n) + O(n) - array + stack
*/
class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n <= 1)
            return n;
        
        if(n == 2)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = helper(n-1, dp) + helper(n-2, dp) + helper(n-3, dp);
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};

/*
Tabulation - iterative
Time complexity : O(n)
Space complexity : O(n) - array space 
*/
class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1)
            return n;
        
        if(n == 2)
            return 1;

        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};

/*
Iterative without extra space 
Time complexity : O(n)
Space complexity : O(1) 
*/
class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1)
            return n;
        if(n == 2)
            return 1;
        int n1 = 0, n2 = 1, n3 = 1, n4;
        for(int i = 3; i <= n; i++){
            n4 = n3 + n2 + n1;
            n1 = n2;
            n2 = n3;
            n3 = n4;
        }
        return n4;
    }
};
