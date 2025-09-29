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