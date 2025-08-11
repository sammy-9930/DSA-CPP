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