/*
Binary search
time : O(logn)
space: O(1)
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r){
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]){
                l = mid + 1;
            }
            else{
                // smallest could be mid or to the left 
                r = mid;
            }
        }
        // answer is obtained when l == r. so return l or r doesn't matter
        return nums[l];
    }
};