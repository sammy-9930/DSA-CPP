class Solution {
public:
    int countSegments(string s) {
        int segment_count = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')){
                segment_count++;
            }
        }
        return segment_count;
    }
};
