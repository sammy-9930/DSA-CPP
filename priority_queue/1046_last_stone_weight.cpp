// Brute force - sorting 
// time complexity: o(n * nlogn) = o(n^2 log n)
// space complexity: o(1) - done in place 
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1){
            sort(stones.begin(), stones.end());
            int y = stones.back();
            stones.pop_back();
            int x = stones.back();
            stones.pop_back();
            if (y != x){
                y = y - x;
                stones.push_back(y);
            }       
        }
        return (stones.size() == 0) ? 0 : stones[0];
    }
};


// optimize - priority queue 
// time complexity: o(n) + o(nlogn) - heapify + actual operation 
// space complexity: o(n) - copy all elements into max heap 
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
