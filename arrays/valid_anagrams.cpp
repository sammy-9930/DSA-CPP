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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (seen.count(diff)){
                return {seen[diff], i};
            }
            seen.insert({nums[i], i});
        }
        return {};
    }
};