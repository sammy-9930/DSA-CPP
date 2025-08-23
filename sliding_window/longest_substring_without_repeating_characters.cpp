/*
Brute force 
time: O(n * m)
space: O(m)

*/

/*
Optimized
time : O(n) n - total number of elements in input 
space : O(m) m - max length of substring 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0; 
        int max_len = 0;
        for (int r = 0; r < s.size(); r++){
            while (seen.find(s[r]) != seen.end()){
                seen.erase(s[l]);
                l += 1;
            }
            seen.insert(s[r]);
            int cur_len = r - l + 1;
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};