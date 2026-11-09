/*
Optimized
Time complexity - O(n)
Space complexity - O(n)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        vector<int> level(n);

        leftMax[0] = height[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        for(int i = 0; i < n; i++){
            level[i] = min(leftMax[i], rightMax[i]);
        }

        for(int i = 0; i < n; i++){
            int curTotal = level[i] - height[i];
            if(curTotal > 0){
                total += curTotal;
            }
        }
        return total;
    }
};

