/*
Brute force 
Time complexity: O(n^2)
Space complexity: O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};

/*
Hash map - one pass 
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (seen.count(diff)){
                return {i, seen[diff]};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
