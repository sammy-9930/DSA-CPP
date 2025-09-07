/*
Brute force
time: O(n^2)
space: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        for(int i = 0; i < height.size(); i++){
            for(int j = i+1; j < height.size(); j++){
                int cur_area = (j - i) * (min(height[i], height[j]));
                max_area = max(max_area, cur_area);
            }
        }
        return max_area;
    }
};

/*
two pointer approach 
time: O(n)
space: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_area = 0;
        while (l < r){
            int cur_area = (r - l) * (min(height[l], height[r]));
            max_area = max(max_area, cur_area);
            if (height[l] < height[r]){
                l ++;
            }
            else{
                r --;
            }
        }
        return max_area;
    }
};