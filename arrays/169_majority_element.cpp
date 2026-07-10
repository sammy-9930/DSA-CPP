/*
using sorting 
time complexity : o(nlogn)
space complexity: o(1) or o(n) depending on the sorting algorithm
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

/*
using hash map
time complexity: o(n)
space complexity: o(n)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int majorityCount = 0;
        unordered_map<int, int> seen;
        for(int number: nums){
            seen[number] += 1;
            if (seen[number] > majorityCount){
                majority = number;
                majorityCount = seen[number];
            }
        }
        return majority;
    }
};

/*
without a hashmap - can be used if a majority element is guaranteed to exist 
time complexity : o(n)
space complexity: o(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int majorityCount = 1;
        for(int i = 1; i < nums.size(); i++){
            
            if (majorityCount == 0){
                majority = nums[i];
            }
            if (majority == nums[i]){
                majorityCount += 1;
            }
            else{
                majorityCount -= 1;
            }
        }
        return majority;
    }
};


