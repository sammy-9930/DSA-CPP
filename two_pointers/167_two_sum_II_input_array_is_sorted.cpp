/*
Brute force solution
Time complexity : O(n^2)
Space complexity : O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int l = 0; l < numbers.size(); l++){
            for(int r = l+1; r < numbers.size(); r++){
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l < r){
            int sum = numbers[l] + numbers[r];
            if(sum == target){
                return {l+1, r+1};
            }
            else if (sum > target){
                r--;
            }
            else{
                l++;
            }
        }
        return {};
    }
};
