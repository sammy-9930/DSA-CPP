class Solution {
public:
    bool isValid(char c){
        return ('a' <= c && c <= 'z') ||
                ('A' <= c && c <= 'Z') || 
                ('0' <= c && c <= '9');
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r){
            if (!isValid(s[l])){
                l += 1;
                continue;
            }

            if (!isValid(s[r])){
                r -= 1;
                continue;
            }

            if (tolower(s[l]) != tolower(s[r]))
                return false;
            
            l += 1;
            r -= 1;
        }
        return true;
    }
};
