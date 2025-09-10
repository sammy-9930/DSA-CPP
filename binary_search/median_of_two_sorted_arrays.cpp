class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] <= nums2[j]){
                res.push_back(nums1[i]);
                i += 1;
            }
            else{
                res.push_back(nums2[j]);
                j += 1;
            }
        }
        while (i < nums1.size()){
            res.push_back(nums1[i]);
            i += 1;
        }
        while (j < nums2.size()){
            res.push_back(nums2[j]);
            j += 1;
        }

        int n = res.size();
        if (n % 2 == 1){
            return res[n / 2];
        }
        return (res[n/2] + res[n/2 - 1])/2.0;
    }
};