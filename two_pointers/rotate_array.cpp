// O(n) time, O(1) space - right rotate 

class Solution {
public:
    void reverse(vector<int>& arr, int start, int end){
        while (start < end){
            swap(arr[start], arr[end]);
            start ++; 
            end --;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-k-1);
        reverse(nums, 0, n-1); 
    }
};


// O(n) time, O(n) space - right rotate 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++){
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }
};

// O(n) time, O(1) space - left rotate 

void reverse(vector<int>& arr, int start, int end){
    while (start < end){
        swap(arr[start], arr[end]);
        start ++; 
        end --;
    }
}
  

void rotate_left(vector<int>& arr, int k){
    int n = arr.size();
    k = k % n;
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
    reverse(arr, 0, n-1);
}


// O(n) time, O(n) space - left rotate 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++){
            temp[i] = nums[(i+k) % n];
        }
        nums = temp;
    }
};