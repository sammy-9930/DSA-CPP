/*
Time complexity: o(n)
Space complexity: o(1)
*/
class Solution {
public:
    bool is_palindrome(int l, int r, string& s){
        while (l < r){
            if (s[l] != s[r]){
                return false;
            }
            l += 1;
            r -= 1;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r){
            if (s[l] != s[r]){
                return (is_palindrome(l+1, r, s) || is_palindrome(l, r-1, s));
            }
            l += 1;
            r -= 1;
        }
        return true;   
    }
};
