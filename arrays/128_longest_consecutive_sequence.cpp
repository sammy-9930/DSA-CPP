/*
Brute force 
Time complexity: O(n^2)
Space complexity: O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> seen(nums.begin(), nums.end());

        for(int num : nums){
            int streak = 1, curr = num;
            while (seen.find(curr + 1) != seen.end()){
                streak++;
                curr++;
            }
            res = max(streak, res);
        }
        return res;
    }
};

/*
Sorting
Time complexity: O(nlogn)
Space complexity: O(1) or O(n) depending on sorting algorithm
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lastElement = INT_MIN;
        int longest = 0;
        int curCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(lastElement == nums[i]-1){
                curCount++;
                lastElement = nums[i];
            }
            else if(lastElement == nums[i]){
                continue;
            }
            else if(lastElement != nums[i]-1){
                curCount = 1;
                lastElement = nums[i];
            }
            longest = max(longest, curCount);
        }
        return longest;
    }
};

/*
Hashset 
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int longest = 0;
        unordered_set<int> store(nums.begin(), nums.end());

        for(int number : store){
            // when number is not found, enter if condition
            if(store.find(number-1) == store.end()){
                int curCount = 1;
                while(store.find(number+1) != store.end()){
                    curCount++;
                    number++;
                }
                longest = max(longest, curCount);
            }
        }
        return longest;
    }
};
