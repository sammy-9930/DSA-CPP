/*
Sorting 
Time: O(nlogn)
Space : O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0;

        while(left+1 < nums.size()){
            if(nums[left] == nums[left+1])
                return nums[left];
            left++;
        }
        return -1;
    }
};
/*
optimized 
Time: O(n)
Space: O(1) 
*/
