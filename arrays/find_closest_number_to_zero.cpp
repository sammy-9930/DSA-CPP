class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (abs(nums[i]) < abs(closest)){
                closest = nums[i];
            }
        }
        if (closest < 0 && std::find(nums.begin(), nums.end(), abs(closest)) != nums.end())
            return abs(closest);
        else 
            return closest;
    }
};