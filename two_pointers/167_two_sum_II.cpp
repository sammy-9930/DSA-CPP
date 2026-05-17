/*
Brute force - TLE 
time complexity: o(n^2)
space complexity: O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++){
            for(int j = i+1; j < numbers.size(); j++){
                int cur_sum = numbers[i] + numbers[j];
                if (cur_sum == target)
                    return {i+1, j+1};
            }
        }
        return {};
    }
};

/*
Optimized solution - two pointers
time complexity: O(n) n - size of i/p array 
space complexity: O(1) 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        while (i < j){
            int cur_sum = numbers[i] + numbers[j];
            if (cur_sum == target)
                return {i+1, j+1};
            else if (cur_sum > target)
                j--;
            else
                i++;
        }
        return {};
    }
};
