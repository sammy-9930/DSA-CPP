/*
two pointers
time : o(m + n), space:o(m + n)
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int m = word1.size();
        int n = word2.size();
        int i = 0, j = 0;
        while (i < m && j < n){
            res += word1[i];
            i++;
            res += word2[j];
            j++;
        }
        while (i < m){
            res += word1[i];
            i++;
        }
        while (j < n){
            res += word2[j];
            j++;
        }
        return res;
    }
};

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int m = word1.size();
        int n = word2.size();
        int i = 0, j = 0;
        while (i < m && j < n){
            res += word1[i];
            i++;
            res += word2[j];
            j++;
        }
        res += word1.substr(i);
        res += word2.substr(j);
        return res;
    }
};

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int m = word1.size();
        int n = word2.size();
        int i = 0, j = 0;
        while (i < m || j < n){
            if (i < m){
                res += word1[i];
                i++;
            }
            if (j < n){
                res += word2[j];
                j++;
            }
        }
        return res;
    }
};