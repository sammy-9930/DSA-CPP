/*
Brute force
time complexity: O(n^2)
space complexity: O(1)
*/
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res(arr.size(), 0);
        for(int i = 0; i < arr.size(); i++){
            int curMax = -1;
            for(int j = i+1; j < arr.size(); j++){
                if(arr[j] > curMax)
                    curMax = arr[j];
            }
            res[i] = curMax;
        }
        return res;
    }
};

/*
Suffix Max
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);
        int rightMax = -1;
        for(int i = n-1; i >= 0; i--){
            res[i] = rightMax;
            rightMax = max(arr[i], rightMax);
        }
        return res;
    }
};
