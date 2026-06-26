/*
Iteration two pass 
Time complexity: o(n)
Space complexity: o(n)
*/
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < 2; i++){
            for(int num: nums)
                ans.push_back(num);
        }
        return ans;
    }
};

/*
Iteration one pass 
Time complexity: o(n)
Space complexity: o(n) - n = size of i/p array 
*/
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n*2, 0);
        for(int i = 0; i < n; i++){
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};
