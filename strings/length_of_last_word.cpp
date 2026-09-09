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

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int count;
        while(i >= 0){
            if (s[i] != ' '){
                count = 0;
                while (i >= 0 && s[i] != ' '){
                    count++;
                    i--;
                }
                break;
            }
            i--;
        }
        return count;
    }
};

// starting from beginning of string
class Solution {
public:
    int lengthOfLastWord(string s) {
        int word_length = 0;
        int i = 0;
        while (i < s.size()){
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')){
                int count = 0;
                while(i < s.size() && s[i] != ' '){
                    count++;
                    i++;
                }
                word_length = count;
            }
            else{
                i++;
            }
        }
        return word_length;
    }
};
