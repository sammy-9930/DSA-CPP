/*
Brute Force Approach
time : O(N^2)
space : O(N)
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> count;
            int maxFreq = 0;
            int windowLen = 0;
            for (int j = i; j < s.size(); j++) {
                count[s[j]]++;
                maxFreq = max(maxFreq, count[s[j]]);
                windowLen = j - i + 1;
                if (windowLen - maxFreq <= k){
                    res = max(res, windowLen);
                }
            }
        }
        return res;
    }
};

/*
sliding Window Approach
time : O(N)
space : O(N)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0; 
        int maxLen = 0;
        unordered_map<char, int> count;
        int windowLen = 0;
        int maxFreq = 0;
        for(int r = 0; r < s.size(); r++){
            // add char in map 
            count[s[r]] += 1;
            // WindowLen - count[max_freq] <= k - valid 
            maxFreq = max(maxFreq, count[s[r]]);
            windowLen = r - l + 1;
            // consider as a possible answer 
            if (windowLen - maxFreq <= k){
                maxLen = max(maxLen, windowLen);
            }
            // modify our window 
            else{
                count[s[l]] -= 1;
                l += 1;
            }
        }
        return maxLen;
    }
};



