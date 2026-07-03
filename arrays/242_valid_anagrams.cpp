#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


/*
Using sorting 
Time complexity: O(nlogn + mlogm)
Space complexity: O(1) or O(n + m) depending on the sorting algorithm
n is the length of string s
m is the length of string t 
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

/*
Using hash map
Time complexity: O(n + m) n- size of i/p 
Space complexity: O(1)
n is the length of string s and m is the length of string t 
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for(int i = 0; i < s.length(); i++){
            s_map[s[i]]++;
            t_map[t[i]]++;
        }
        return s_map == t_map; 
    }
};

/*
Hash Table - using array
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        vector<int> sMap(26, 0);
        vector<int> tMap(26, 0);
        for(int i = 0; i < s.size(); i++){
            sMap[s[i] - 'a'] += 1;
            tMap[t[i] - 'a'] += 1;
        }
        return sMap == tMap;
    }
};