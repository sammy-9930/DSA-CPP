/*
Brute force 
time: O(n^3logn)
space: O(n)
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());

        for (int i = 0; i < s2.size(); i++){
            for(int j = i; j < s2.size(); j++){
                string subStr = s2.substr(i, j - i + 1);
                sort(subStr.begin(), subStr.end());

                if (subStr == s1){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        unordered_map<char, int> countS1;
        unordered_map<char, int> countS2;

        for(auto c : s1){
            countS1[c]++;
        }

        int l = 0;
        for(int r = 0; r < s2.length(); r++){
            countS2[s2[r]]++;

            while ((r - l + 1) > s1.size()){
                countS2[s2[l]]--;
                if (countS2[s2[l]] == 0)
                    countS2.erase(s2[l]);
                l++;
            }

            if ((r - l + 1) == s1.size()){
                if (countS1 == countS2)
                    return true;
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
        if (s1.size() > s2.size()){
            return false;
        }

        vector<int> s1_count(26, 0);
        vector<int> s2_count(26, 0);

        for (int i = 0; i < s1.size(); i++){
            s1_count[s1[i] - 'a']++;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); r++){
            s2_count[s2[r] - 'a']++;

            if ((r - l + 1) > s1.size()){
                s2_count[s2[l] - 'a']--;
                l += 1;
            }

            if (s1_count == s2_count){
                return true;
            }
        }
        return false;
    }
};