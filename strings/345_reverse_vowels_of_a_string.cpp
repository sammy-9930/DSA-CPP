// using pointers 
class Solution {
public:
    string reverseVowels(string s) {
        int l = 0; 
        int r = s.size()-1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (l < r){
            while (l < r && vowels.count(s[l]) == 0){
                l++;
            }
            while (l < r && vowels.count(s[r]) == 0){
                r--;
            }
            if (l < r){
                swap(s[l], s[r]);
                l++;
                r--;
            } 
        }
        return s;
    }
};
  
