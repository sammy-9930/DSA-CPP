// max heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]] += 1;
        }
        priority_queue<pair<int, int>> pq;
        for (auto element: count){
            pq.push({element.second, element.first});
        }
        while (k != 0){
            res.push_back(pq.top().second);
            pq.pop();
            k --;
        }
        return res;  
    }
};

// min heap 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]] += 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto& element: count){
            minHeap.push({element.second, element.first});
            if (minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};