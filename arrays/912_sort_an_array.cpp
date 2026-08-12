/*
Merge sort 
Time complexity: O(nlogn)
Space complexity: O(n)
*/
class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high){
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else 
                temp.push_back(arr[right++]);
        }
        while(left <= mid)
            temp.push_back(arr[left++]);
        while(right <= high)
            temp.push_back(arr[right++]);

        for(int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if (low >= high)
            return;
        int mid = (low + high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
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
