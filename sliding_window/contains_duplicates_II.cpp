// using hash map 
// time: o(n) ; space: o(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> values;
        for (int i = 0; i < nums.size(); i++){
            if (values.find(nums[i]) != values.end()){
                if ((i - values[nums[i]]) <= k)
                    return true; 
            }
            values[nums[i]] = i; 
        }
        return false;
    }
};

// using hash set 
// time : O(n) space: O(k)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        int l = 0; 
        for (int r = 0; r < nums.size(); r++){
            if (r - l > k){
                seen.erase(nums[l]);
                l += 1;
            }
            if (seen.find(nums[r]) != seen.end())
                return true; 
            seen.insert(nums[r]);
        }
        return false;
    }
};