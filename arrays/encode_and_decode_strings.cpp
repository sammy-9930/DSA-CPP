/*
optimal solution
time: O(m+n) for each encode and decode function calls
space: O(m+n) for each encode and decode function calls
*/
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(const string& s: strs){
            res.append(to_string(s.size()));
            res.append("#");
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        while (i < s.size()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            res.push_back(s.substr(j+1, length));
            i = 1 + j + length;
        }
        return res;
    }
};
