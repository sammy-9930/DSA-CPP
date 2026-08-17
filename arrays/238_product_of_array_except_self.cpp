/*
Brute force approach
Time complexity: O(n^2)
Space complexity: O(n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int prod = 1;
            for(int j = 0; j < n; j++){
                if (i != j){
                    prod = prod * nums[j];
                }
            }
            res[i] = prod;
        }
        return res;
    }
};

/*
Division
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        int product = 1;
        for(int n : nums){
            if (n == 0){
                zeroCount++;
                continue;
            }
            product = product * n;
        }

        for(int i = 0; i < nums.size(); i++){
            if (zeroCount >= 2){
                nums[i] = 0;
            }
            else if (zeroCount == 1 && nums[i] != 0){
                nums[i] = 0;
            }
            else if (zeroCount == 1 && nums[i] == 0){
                nums[i] = product;
            }
            else{
                nums[i] = product / nums[i];
            }
        }
        return nums;
    }
};

/*
Prefix and Suffix 
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 1;
        suffix[n-1] = 1;

        for(int i = 1; i <= n-1 ; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        for(int i = 0; i < n; i++){
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};
