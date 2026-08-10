/*
using vector as a stack
time complexity : O(n)
space complexity: O(n)
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int& a: asteroids){
            while (!res.empty() &&  res.back() > 0 && a < 0){
                int diff = a + res.back();
                if (diff == 0){
                    res.pop_back();
                    a = 0;
                    break;
                }
                else if (diff < 0){
                    res.pop_back();
                }
                else{
                    a = 0;
                    break;
                }
            }
            if (a!= 0)
                res.push_back(a);
        }
        return res;
    }
};
