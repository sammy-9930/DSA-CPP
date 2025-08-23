class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int longest_streak = 1;
        int current_streak = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1])
                continue; 
            else if (nums[i] == nums[i-1] + 1){
                current_streak += 1;
            }
            else{
                longest_streak = max(longest_streak, current_streak);
                current_streak = 1;
            }
        }
        return max(longest_streak, current_streak);
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int number: numSet){
            if (!numSet.count(number-1)){
                int current_streak = 1; 
                while (numSet.count(number + current_streak)){
                    current_streak += 1;  
                }
                longest = max(longest, current_streak);
            } 
        }
        return longest;
    }
};