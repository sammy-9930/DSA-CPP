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
            if (cur_profit > max_profit){
                max_profit = cur_profit;
            }
        }
        return max_profit;
    }
};