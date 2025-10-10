/*
Recursive merge sort 
Time : O(nlogn)
Space : O(2n + logn) = O(n + logn)
THE ONLY SORTING ALGORITHM THAT USES EXTRA SPACE 
*/
class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> left(nums.begin() + low, nums.begin() + mid + 1);
        vector<int> right(nums.begin() + mid + 1, nums.begin() + high + 1);

        int m = left.size();
        int n = right.size();
        int i = 0, j = 0, k = low;

        while (i < m && j < n){
            if (left[i] <= right[j]){
                nums[k++] = left[i++];
            }
            else{
                nums[k++] = right[j++];
            }
        }
        while (i < m)
            nums[k++] = left[i++]; 
        while (j < n)
            nums[k++] = right[j++];
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if (low < high){
            int mid = (low + high) / 2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        mergeSort(nums, low, high);
        return nums;
    }
};