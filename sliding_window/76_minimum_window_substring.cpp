/*
Sliding window
Time complexity : O(m + n) 
Space complexity : O(n) 
m = length of string s
n = length of string t
*/
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()){
            return "";
        }

        unordered_map<char, int> tMap;
        unordered_map<char, int> sMap;
        int need = 0;
        int have = 0;
        int curLen = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        for(char c : t){
            tMap[c]++;
        }

        need = tMap.size();

        int l = 0;
        for(int r = 0; r < s.size(); r++){
            if(tMap.count(s[r])){
                sMap[s[r]]++;
                if(tMap[s[r]] == sMap[s[r]]){
                    have++;
                }
            }

            while(have == need){
                curLen = r - l + 1;
                if(curLen < minLen){
                    minLen = curLen;
                    startIdx = l;
                }

                if(tMap.count(s[l])){
                    sMap[s[l]]--;
                    if(sMap[s[l]] < tMap[s[l]]){
                        have--;
                    }
                }
                l++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
