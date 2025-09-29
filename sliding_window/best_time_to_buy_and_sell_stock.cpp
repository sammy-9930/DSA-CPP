/*
Brute force 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for(int l = 0; l < prices.size(); l++){
            for(int r = l; r < prices.size(); r++){
                if(prices[r] - prices[l] > maxProfit){
                    maxProfit = prices[r] - prices[l];
                }
            }
        }
        return maxProfit;
    }
};

/* two pointer
time : O(n), space: O(1)
*/  

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0; 
        int max_profit = 0;
        for(int r = 0; r < prices.size(); r++){
            if (prices[r] < prices[l]){
                l = r;
            }
            int cur_profit = prices[r] - prices[l];
            max_profit = max(max_profit, cur_profit);
        }
        return max_profit;
    }
};