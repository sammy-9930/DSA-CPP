/*Recursion - TLE*/
class Solution {
public:
    int helper(vector<int>& prices, int start){
        // base condition 
        if (start >= prices.size())
            return 0;
        int maxProfit = 0;

        for(int buy = start; buy < prices.size(); buy++){
            for(int sell = buy + 1; sell < prices.size(); sell++){
                if (prices[sell] > prices[buy]){
                    int profit = (prices[sell] - prices[buy]) + helper(prices, sell+1);
                    maxProfit = max(maxProfit, profit);
                }
            }
        }
        return maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        return helper(prices, 0);
    }
};

// Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if (prices[i] > prices[i-1]){
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }
};

