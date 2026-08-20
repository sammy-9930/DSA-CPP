// max heap
// time: O(nlogn)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        vector<int> res;
        priority_queue<pair<int, int>> maxHeap;

        // store the element and its frequency 
        for(int i = 0; i < nums.size(); i++){
            seen[nums[i]] += 1;
        }

        // push (freq, value) into the maxHeap
        for(auto itr = seen.begin(); itr != seen.end(); itr++){
            maxHeap.push({itr->second, itr->first});
        }

        // extract elements into res 
        while (k > 0){
            auto var = maxHeap.top();
            maxHeap.pop();
            res.push_back(var.second);
            k--;
        }

        return res;
    }
};

// min heap 
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
