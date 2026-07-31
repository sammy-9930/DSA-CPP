/*
Brute force solution
time complexity: O(n^2)
space complexity: O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        while (true){
            size_t pos = string::npos;
            if ((pos = s.find("()")) != string::npos){
                s.erase(pos, 2);
                continue;
            }
            if ((pos = s.find("[]")) != string::npos){
                s.erase(pos, 2);
                continue;
            }
            if ((pos = s.find("{}")) != string::npos){
                s.erase(pos, 2);
                continue;
            }
            break;
        }
        return s.empty();
    }
};

/*
Stack
time complexity: O(n)
space complexity: O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> charMap = { 
            {')' ,'('},
            {'}' , '{'}, 
            {']' , '['}
        };
        for (char c : s){
            if (charMap.count(c)){
                if (!st.empty() && st.top() == charMap[c]){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                st.push(c);
            }  
        }
        return st.empty();
    }
};
