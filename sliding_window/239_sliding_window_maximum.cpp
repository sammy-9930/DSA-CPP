/*
Brute force 
Time complexity : O(n . k) 
Space complexity : O(n)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i <= n-k; i++){
            int curMax = nums[i];
            int j = i;
            int tmp = k;
            while(tmp){
                if(nums[j] > curMax){
                    curMax = nums[j];
                }
                tmp--;
                j++;
            }
            res.push_back(curMax);
        }
        return res;
    }
};

