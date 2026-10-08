/*
Brute force
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    bool isAlphaNum(char c){
        if (c >= 'a' && c <= 'z' ||
            c >= 'A' && c <= 'Z' ||
            c >= '0' && c <= '9'){
                return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        string sNew = "";
        for(char c: s){
            if (isAlphaNum(c)){
                sNew += tolower(c);
            }
        }
        string sRev(sNew.rbegin(), sNew.rend());
        return sNew == sRev;
    }
};


/*
Two pointers
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    bool isAlphaNum(char c){
        if((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
            return true;
        return false;
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r){
            if(isAlphaNum(s[l])){
                if(isAlphaNum(s[r])){
                    if(tolower(s[l]) == tolower(s[r])){
                        l++;
                        r--;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    r--;
                }
            }
            else{
                l++;
            }
        }
        return true;
    }
};
