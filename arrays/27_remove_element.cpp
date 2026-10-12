/*
Brute force
time complexity: O(n)
space complexity: O(n)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> tmp;
        for(int num : nums){
            if(num != val){
                tmp.push_back(num);
            }
        }
        for(int i = 0; i < tmp.size(); i++){
            nums[i] = tmp[i];
        }
        return tmp.size();
    }
};

/*
Two pointer
time complexity: O(n)
space complexity: O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
