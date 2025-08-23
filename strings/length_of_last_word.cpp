// starting from end of string 
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int count = 0;
        // skip trailing spaces 
        while(i >= 0 && s[i] == ' ')
            i--;

        while(i >= 0 && s[i] != ' '){
            count += 1;
            i --;
        }
        return count;
    }
};

// starting from beginning of string 
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        int count = 0;
        while (i < s.size()){
            if (s[i] == ' '){
                while (i < s.size() && s[i] == ' '){
                    i += 1;
                }
                if (i == s.size()){
                    return count;
                }
                count = 0;
            }
            else{
                count += 1;
                i += 1;
            }
        }
        return count;
    }
};