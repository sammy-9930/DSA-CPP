/*
Brute force approach
Time complexity: O(n^2)
Space complexity: O(1)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if (nums[i] == nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Sorting
Time complexity: O(nlogn)
Space complexity: O(1) or O(n) depending on the sorting algorithm
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
};

/*
Hashset
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); i++){
            if (seen.count(nums[i]) == 1){
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};
