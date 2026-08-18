/*
Brute force 
Time complexity: O(n^2)
Space complexity: O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> store(nums.begin(), nums.end());

        for(int num : nums){
            int streak = 0, curr = num;
            while (store.find(curr) != store.end()){
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
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int curr = nums[0], streak = 0, i = 0, res = 0;
        while (i < nums.size()){
            // start of new sequence
            if (curr != nums[i]){
                curr = nums[i];
                streak = 0;
            }
            // check for duplicates 
            while (i < nums.size() && curr == nums[i]){
                i++;
            }
            streak++;
            curr++;
            res = max(res, streak);
        }
        return res;
    }
};
