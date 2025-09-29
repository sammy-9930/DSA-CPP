/*
Using priority queue (min-heap)
time complexity: O(m log k)
space complexity: O(k) or O(1) depending on the sorting algorithm

m is the number of calls to add function
*/
class KthLargest {
private: 
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int number : nums){
            minHeap.push(number);
            if (minHeap.size() > k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > k){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/*
Brute force approach: sorting 
time complexity: O(m * n log n)
m is the number of calls to add function and n is the current size of the array
space complexity: O(n) or O(1) depending on the sorting algorithm
*/
class KthLargest {
public:
    int k;
    vector<int> arr;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->arr = nums;
    }
    
    int add(int val) {
        arr.push_back(val);
        sort(arr.begin(), arr.end());
        return arr[arr.size() - k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */