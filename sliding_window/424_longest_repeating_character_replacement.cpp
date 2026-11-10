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
space : O(1) - max size of unordered_map = 26
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int maxFreq;
        int longest = 0;
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);

            if((r - l + 1) - maxFreq > k){
                count[s[l]]--;
                l++;
            } 
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};
