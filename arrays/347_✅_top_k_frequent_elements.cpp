/*
Brute force - sorting
Time complexity : O(nlogn)
Space complexity : O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> frequency;
        for(int number : nums){
            frequency[number]++;
        }

        vector<pair<int, int>> arr;
        for(auto element : frequency){
            arr.push_back({element.second, element.first});
        }

        sort(arr.rbegin(), arr.rend());

        for(int i = 0; i < k; i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};

/*
Using a min heap - storing pair of {freq, value} 
Time complexity : O(nlogk) n - length of array, k - number of top frequent elements 
Space complexity : O(n + k) 
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // store the element and its frequency 
        for(int i = 0; i < nums.size(); i++){
            seen[nums[i]] += 1;
        }

        // maintaining a minHeap of max size = k 
        for(auto itr = seen.begin(); itr != seen.end(); itr++){
            minHeap.push({itr->second, itr->first});
            if (minHeap.size() > k){
                minHeap.pop();
            }
        }

        // copy elements into res
        while (k > 0){
            auto var = minHeap.top();
            minHeap.pop();
            res.push_back(var.second);
            k--;
        }

        return res;
    }
};
