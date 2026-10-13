/*
Merge sort 
Time complexity: O(nlogn)
Space complexity: O(n)
*/
class Solution {
public:
    void merge(int low, int mid, int high, vector<int>& nums, vector<int>& temp){
        int i = low, j = mid+1;
        int k = low;
        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }

        while(i <= mid){
            temp[k++] = nums[i++];
        }

        while(j <= high){
            temp[k++] = nums[j++];
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i];
        }
    }

    void mergeSort(int low, int high, vector<int>& nums, vector<int>& temp){
        if(low >= high){
            return;
        }
        int mid = (low + high)/2;
        mergeSort(low, mid, nums, temp);
        mergeSort(mid+1, high, nums, temp);
        merge(low, mid, high, nums, temp);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, -1);
        mergeSort(0, n-1, nums, temp);
        return nums;
    }
};

/*
Quick Sort 
Time complexity: O(nlogn)
Space complexity: 
As per leetcode restriction => issues taking first element as pivot 
*/
class Solution {
public:
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while (i < j){
            while (i <= high && nums[i] <= pivot)
                i++;
            while (j >= low && nums[j] > pivot)
                j--;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }

    void quickSort(vector<int>&nums, int low, int high){
        if (low < high){
            int pIndex =  partition(nums, low, high);
            quickSort(nums, low, pIndex-1);
            quickSort(nums, pIndex+1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        return nums;
    }
};
