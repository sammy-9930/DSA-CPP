#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


// using sorting 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false; 
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//using hash map (one pass)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        unordered_map<char, int> seen;
        for (int i = 0; i < s.size(); i++){
            seen[s[i]]++;
            seen[t[i]]--;
        }

        for(auto pair: seen){
            if (pair.second != 0){
                return false;
            }
        }
        return true;
    }
};

// using fixed 26 slot array 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        vector<int> seen(26, 0);
        for(int i = 0; i < s.size(); i++){
            seen[s[i] - 'a'] += 1;
            seen[t[i] - 'a'] -= 1;
        }

        for(int count : seen){
            if (count != 0)
                return false;
        }
        return true;
    }
};