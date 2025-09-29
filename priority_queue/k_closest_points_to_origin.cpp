/*
max heap
 time : O(nlogk), space: O(k)  n - length of input array 
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for (auto& p : points){
            int x = p[0], y = p[1];
            int dist = (x*x) + (y*y);
            maxHeap.push({dist, {x, y}});
            if (maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> res;
        while(!maxHeap.empty()){
            auto [dist, coor] = maxHeap.top();
            res.push_back({coor.first, coor.second});
            maxHeap.pop();
        }
        return res;
    }
};

//Min-heap 
// time: O(nlogn)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
            > minHeap;
        for (auto& p : points){
            int x = p[0], y = p[1];
            int dist = (x*x) + (y*y);
            minHeap.push({dist, {x, y}});
        }
        vector<vector<int>> res;
        while (k > 0){
            auto [dist, coor] = minHeap.top();
            res.push_back({coor.first, coor.second});
            minHeap.pop();
            k --;
        }
        return res;
    }
};