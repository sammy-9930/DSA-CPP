/*
time complexity: O(n * m) n - no of strings in strs, m - length of first string 
space complexity: O(m)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            while(j < prefix.size() && j < strs[i].size()){
                if(prefix[j] != strs[i][j]){
                    break;
                }
                j++;
            }
            prefix = prefix.substr(0, j);
        }
        return prefix;
    }
};
