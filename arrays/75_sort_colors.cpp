/*
Time complexity - O(n) + O(n) = O(2n) ~ O(n) 
Space complexity - O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        for(int number : nums){
            if(number == 0)
                zero++;
            else if(number == 1)
                one++;
            else
                two++;
        }

        for(int i = 0; i < zero; i++){
            nums[i] = 0;
        }

        for(int i = zero; i < zero + one; i++){
            nums[i] = 1;
        }

        for(int i = zero + one; i < zero + one + two; i++){
            nums[i] = 2;
        }
    }
};
