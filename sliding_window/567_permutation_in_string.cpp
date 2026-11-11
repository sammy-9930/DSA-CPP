/*
Brute force 
time: O(n.m)
space: O(26)
n - size of s2,  m - size of s1
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Count(26, 0);
        for(char c : s1){
            s1Count[c - 'a']++;
        }

        int k = s1.size();

        for(int i = 0; i < s2.size(); i++){
            vector<int> s2Count(26, 0);
            for(int j = i; j < s2.size(); j++){
                s2Count[s2[j] - 'a']++;

                if((j - i + 1) > k)
                    break;

                if((j - i + 1) == k && s1Count == s2Count){
                    return true;
                }
            }
        }
        return false;
    }
};


/*
Sliding window 
time: o(n + m)
space: o(1) atmost 26 char 
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        int k = s1.size();

        for(char c : s1){
            s1Count[c - 'a'] += 1;
        }

        int l = 0;
        for(int r = l; r < s2.size(); r++){
            s2Count[s2[r] - 'a'] += 1;

            if((r - l + 1) > k){
                s2Count[s2[l] - 'a'] -= 1;
                l++;
            }

            if((r - l + 1) == k && s1Count == s2Count)
                return true;
        }
        return false;
    }
};
