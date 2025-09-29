// without memoization

class Solution {
public:
    void decode(string& s, int& num_ways, int idx){
        if (idx == s.size()){
            num_ways += 1;
            return; 
        }

        if (s[idx] != '0')
            decode(s, num_ways, idx+1);

        if (idx + 1 < s.size() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6')))
            decode(s, num_ways, idx+2);

    }
    int numDecodings(string s) {
        int num_ways = 0;
        decode(s, num_ways, 0);
        return num_ways;
    }
};

// memoization
class Solution {
public:
    int helper(string& s, int idx, vector<int>& dp){
        if (idx == s.size()){
            return 1;
        }

        if (dp[idx] != -1)
            return dp[idx];

        if (s[idx] == '0')
            return 0;

        // single digit 
        dp[idx] = helper(s, idx + 1, dp);

        // doublt digit
        if((idx + 1) < s.size() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6'))){
            dp[idx] += helper(s, idx + 2, dp);
        }
        return dp[idx];
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return helper(s, 0, dp);
    }
};