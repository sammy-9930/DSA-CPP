/*
Time: O(n + m)
Space: O(m)
n - length of string s 
m - length of total number of unique characters in the strings t and s 
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        for(auto c : t){
            countT[c]++;
        }

        int have = 0, need = countT.size();
        int resLen = INT_MAX;
        pair<int, int> res = {-1, -1};
        int l = 0;

        for(int r = 0; r < s.length(); r++){
            char c = s[r];
            window[c]++;

            if(countT.count(c) && countT[c] == window[c]){
                have += 1;
            }

            while (have == need){
                if ((r - l + 1) < resLen){
                    resLen = r - l + 1;
                    res = {l , r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have -= 1;
                }
                l += 1;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};