/*
Brute force solution 
Time complexity: O(n^2)
Space complexity: O(n)
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        while (tokens.size() > 1){
            for(int i = 0; i < tokens.size(); i++){
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                    int a = stoi(tokens[i-2]);
                    int b = stoi(tokens[i-1]);
                    int result;
                    if (tokens[i] == "+") 
                        result = a + b;
                    else if (tokens[i] == "-")
                        result = a - b;
                    else if (tokens[i] == "*")
                        result = b * a;
                    else if (tokens[i] == "/")
                        result = a / b;
                    
                    tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
                    tokens.insert(tokens.begin() + i - 2, to_string(result));
                    break;
                }

            }
        }
        return stoi(tokens[0]);
    }
};

/*
Optimization - using stack
Time complexity:
Space complexity: 
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string token : tokens){
            if (token == "+" || token == "-" || token == "*" || token =="/"){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                int result;
                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else if (token == "/") result = a / b;
                stk.push(result);
            }
            else{
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};
