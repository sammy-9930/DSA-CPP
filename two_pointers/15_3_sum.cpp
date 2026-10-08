/*
Brute force
Time complexity: O(n^3)
Space complexity: O(1) excluding space used by sorting algorithm
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                for(int k = j+1; k < nums.size(); k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        res.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

/*
Two pointer
Time complexity: O(n^2)
Space complexity: O(1) excluding space used by sorting algorithm 
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                    while(k > j && nums[k] == nums[k+1])
                        k--;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return res;
    }
};
