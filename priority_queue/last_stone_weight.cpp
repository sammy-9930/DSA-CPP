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
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        while (maxHeap.size() > 1){
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if (x != y){
                y = y - x;
                maxHeap.push(y);
            }
        }
        return (maxHeap.size() == 0 ? 0 : maxHeap.top());
    }
};
