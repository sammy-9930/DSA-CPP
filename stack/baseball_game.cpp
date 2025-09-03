class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for(int i = 0; i < operations.size(); i++){
            if (operations[i] == "C"){
                sum -= st.top();
                st.pop();
            }
            else if (operations[i] == "D"){
                int new_tot = (2 * st.top());
                sum += new_tot;
                st.push(new_tot);
            }
            else if (operations[i] == "+"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                st.push(top2);
                st.push(top1);
                sum += (top1 + top2);
                st.push(top1 + top2);
            }
            else{
                st.push(stoi(operations[i]));
                sum += st.top();
            }
        }
        return sum;
    }
};

