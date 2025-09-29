/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n; 
        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 1; 
        for (int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n; 
        int n1 = 0, n2 = 1, n3;
        for (int i = 2; i <= n; i++){
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
};