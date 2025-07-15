// without memoization

class Solution {
public:
    void decode(string& s, int& num_ways, int idx){
        if (idx == s.size()){
            num_ways += 1;
            return; 
        }

        if (s[idx] != '0')
            decode(s, num_ways, idx+1);

        if (idx + 1 < s.size() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6')))
            decode(s, num_ways, idx+2);

    }
    int numDecodings(string s) {
        int num_ways = 0;
        decode(s, num_ways, 0);
        return num_ways;
    }
};