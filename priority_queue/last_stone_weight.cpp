// Brute force - sorting 
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1){
            sort(stones.begin(), stones.end());
            int high = stones.back();
            stones.pop_back();
            int sec_high = stones.back();
            stones.pop_back();
            if (high > sec_high)
                stones.push_back(high - sec_high);
        }
        return stones.empty() ? 0 : stones[0];
    }
};


// optimize - priority queue 
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1){
            int high = pq.top();
            pq.pop();
            int sec_high = pq.top();
            pq.pop();
            if (high > sec_high){
                int new_wt = high - sec_high;
                pq.push(new_wt);
            }
        }
        if (!pq.empty())
            return pq.top();
        return 0;
    }
};