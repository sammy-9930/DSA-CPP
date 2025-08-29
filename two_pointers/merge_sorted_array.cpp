/*
sorting 
time : o(m + n)log(m+n)
space: o(1) or o(m+n)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++){
            nums1[m + i] = nums2[i];
        }
        return sort(nums1.begin(), nums1.end());
    }
};


/*
using three pointers 
time : o(m + n)
space : o(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0){
            if (nums1[i] >= nums2[j]){
                nums1[k] = nums1[i];
                i --;
                k --;
            }
            else{
                nums1[k] = nums2[j];
                j --;
                k --;
            }
        }
        while (j >= 0){
            nums1[k] = nums2[j];
            k --;
            j --;
        }
    }
};