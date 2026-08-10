/*
Brute force approach
time complexity: O(n^2)
space complexity: O(n)
*/
class StockSpanner {
public:
    vector<int> arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        arr.push_back(price);
        int i = arr.size() - 2;
        while (i >= 0 && arr[i] <= price){
            count++;
            i--;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
