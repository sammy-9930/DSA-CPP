/* 
Recursion - TLE - 0 to n 
Time Complexity: O(2^(m+n)) where m and n are the lengths of text1 and text2 respectively.
Space Complexity: O(m+n) for the recursion stack.
*/
class Solution {
public:
    int helper(string& text1, string& text2, int idx1, int idx2){
        if (idx1 == text1.size() || idx2 == text2.size()){
            return 0;
        }
        
        if (text1[idx1] == text2[idx2]){
            return 1 + helper(text1, text2, idx1 + 1, idx2 + 1);
        }

        return max(helper(text1, text2, idx1, idx2 + 1), 
                   helper(text1, text2, idx1 + 1, idx2));

    }
    int longestCommonSubsequence(string text1, string text2) {
        return helper(text1, text2, 0, 0);
    }
};

/*
Memoization - 0 to n 
Time complexity: O(m*n) where m and n are the lengths of text1 and text2 respectively.
Space complexity: O(m*n) for the memoization table.
*/
class Solution {
public:
    int helper(string& text1, string& text2, int idx1, int idx2, vector<vector<int>>& arr){
        if (idx1 >= text1.size() || idx2 >= text2.size()){
            return 0;
        }

        if (arr[idx1][idx2] != -1){
            return arr[idx1][idx2];
        }
        
        if (text1[idx1] == text2[idx2]){
            arr[idx1][idx2] =  1 + helper(text1, text2, idx1 + 1, idx2 + 1, arr);
            return arr[idx1][idx2];
        }

        arr[idx1][idx2] = max(helper(text1, text2, idx1, idx2 + 1, arr), 
                   helper(text1, text2, idx1 + 1, idx2, arr));
        return arr[idx1][idx2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> arr(n+1, vector<int>(m+1, -1));
        return helper(text1, text2, 0, 0, arr);
    }
};

/*
Recursion - TLE - n to 0 
Time Complexity: O(2^(m+n)) where m and n are the lengths of text1 and text2 respectively.
Space Complexity: O(m+n) for the recursion stack.
*/
class Solution {
public:
    // n to 0 - recursion 
    int helper(string &text1, string &text2, int idx1, int idx2){
        // base cond 
        if (idx1 < 0 || idx2 < 0)
            return 0;

        // strings match
        if (text1[idx1] == text2[idx2])
            return 1 + helper(text1, text2, idx1-1, idx2-1); 

        // strings don't match 
        return max(helper(text1, text2, idx1, idx2-1), helper(text1, text2, idx1-1, idx2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int result = helper(text1, text2, n-1, m-1);
        return result;
    }
};

/*
Memoization - n to 0 
Time complexity: O(m*n) where m and n are the lengths of text1 and text2 respectively.
Space complexity: O(m*n) for the memoization table.
*/
class Solution {
public:
    // n to 0 - recursion 
    int helper(string &text1, string &text2, int idx1, int idx2, vector<vector<int>>& dp){
        // base cond 
        if (idx1 < 0 || idx2 < 0)
            return 0;

        // memoization 
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        // strings match
        if (text1[idx1] == text2[idx2])
            return dp[idx1][idx2] = 1 + helper(text1, text2, idx1-1, idx2-1, dp); 

        // strings don't match 
        return dp[idx1][idx2] = max(helper(text1, text2, idx1, idx2-1, dp), 
                                    helper(text1, text2, idx1-1, idx2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int result = helper(text1, text2, n-1, m-1, dp);
        return result;
    }
};