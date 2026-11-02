/*
Brute force solution - recursion
Time complexity : 
Space complexity : 
UPDATE LATER 
*/


/*
Optimized solution 
Time complexity : O(n) 
Space complexity : O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }
};
