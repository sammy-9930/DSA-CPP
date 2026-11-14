/*
Brute force approach
m - length of string s, n - length of string t 
Time complexity : O(n + m^2 . k)
Space complexity : O(k)  - max no of entries into map is 26
*/
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length())
            return "";
        
        unordered_map<char, int> tMap;
        for(char c: t){
            tMap[c]++;
        }

        int minLen = INT_MAX;
        int startIdx = 0;

        for(int i = 0; i < s.length(); i++){
            unordered_map<char, int> sMap;
            for(int j = i; j < s.length(); j++){
                sMap[s[j]]++;

                bool valid = true;
                for(auto itr : tMap){
                    if(sMap[itr.first] < tMap[itr.first]){
                        valid = false;
                        break;
                    }
                }

                if(valid && ((j-i+1) < minLen)){
                    minLen = j - i + 1;
                    startIdx = i;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};


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
