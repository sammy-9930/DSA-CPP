class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        for (auto num : nums){
            if (num == 0)
                zeroCount += 1;
            else if (num == 1)
                oneCount += 1;
            else
                twoCount += 1;
        }

        for(int i = 0; i < zeroCount; i++)
            nums[i] = 0;
        for(int i = zeroCount; i < (zeroCount+oneCount); i++)
            nums[i] = 1;
        for(int i = (zeroCount + oneCount); i < (zeroCount + oneCount + twoCount); i++)
            nums[i] = 2;
    }
};



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size()-1;
        while(mid <= high){
            if (nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low ++; 
                mid ++;
            }
            else if (nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high --;
            }
            else{
                mid += 1;
            }
        }
    }
};

