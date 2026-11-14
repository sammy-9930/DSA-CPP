/*
Brute force approach
Time complexity : O(logn)
Space complexity : O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int first = -1, last = -1;
        
        while(left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] > target){
                right = mid-1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                first = mid;
                right = mid-1;
            }
        }

        left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                last = mid;
                left = mid+1;
            }
        }
        return {first, last};   
    }
};

/*
Optimized solution
*/
class Solution {
public:
    int helper(vector<int>& nums, int& target, bool flag){
        int low = 0, high = nums.size()-1;
        int res = -1;

        while (low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
            else{
                if(flag){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
                res = mid;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = helper(nums, target, true);
        int last = helper(nums, target, false);
        return {first, last};
    }
};
