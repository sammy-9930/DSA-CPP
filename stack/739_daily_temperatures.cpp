/*
Brute force 
time complexity: O(n^2)
space complexity: O(1) but O(n) space for extra array
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        
        for(int i = 0; i < n; i++){
            int j = i + 1;

            while(j < n && temperatures[j] <= temperatures[i])
                j++;

            if (j < n){
                res[i] = j - i;
            }else{
                res[i] = 0;
            }   
        }
        return res;
    }
};

/*
Monotonic stack (optimized)
time complexity: O(n)
space complexity: O(n)
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> stk;
        for(int i = 0; i < temperatures.size(); i++){
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                int index = stk.top();
                stk.pop();
                res[index] = i - index;
            }
            stk.push(i);
            
        }
        return res;
    }
};
