class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (int i = 0; i < asteroids.size(); i++){
            bool alive = true;
            while (!stack.empty() && alive && asteroids[i] < 0 && stack.back() > 0){
                if (-asteroids[i] == stack.back()){
                    // both explode 
                    stack.pop_back();
                    alive = false;
                }
                else if (stack.back() <  -asteroids[i]){
                    // top explodes 
                    stack.pop_back();
                }
                else{
                    // top is bigger, current dies 
                    alive = false;
                }
            }
            if (alive)
                stack.push_back(asteroids[i]);
        }
        return stack;
    }
};