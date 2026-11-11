/*
Brute force solution
Time complexity : O(n^2)
Space complexity : O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int l = 0; l < numbers.size(); l++){
            for(int r = 0; r < numbers.size(); r++){
                if(numbers[l] + numbers[r] == target){
                    return {l+1, r+1};
                }
            }
        }
        return {};
    }
};

/*
Two pointers
Time complexity : O(n) 
Space complexity : O(1)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int curMax = nums[0];

        int l = 0;
        for(int r = l; r < nums.size(); r++){
            if((r - l + 1) <= k){
                curMax = max(curMax, nums[r]);
            }

            if((r - l + 1) == k){
                res.push_back(curMax);
                if(curMax == nums[l]){
                    curMax = 0;
                }
                l++;    
            }
        }
        return res;
    }
};
