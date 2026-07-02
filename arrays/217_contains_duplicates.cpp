#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
Brute force 
Time: O(n2)
Space: O(1)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};

/*
Sorting 
Time: O(nlogn)
Space: O(1) or O(n) depending on the sorting algorithm 
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return false;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if (nums[i-1] == nums[i])
                return true;
        }
        return false;
    }
};


/*
Using Hash Set 
Time: O(n)
Space: O(n) 
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return false;
        unordered_set<int> seen;
        for(int number: nums){
            if (seen.count(number))
                return true; 
            seen.insert(number);
        }
        return false;
    }
};
