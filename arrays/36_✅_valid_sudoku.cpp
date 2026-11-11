/*
Time complexity - O(mn) 
Space complexity - O(mn) 
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_set<char> rows;
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c != '.'){
                    if (rows.find(c) != rows.end())
                        return false;
                    rows.insert(c);
                }  
            }
        }

        for(int i = 0; i < 9; i++){
            unordered_set<char> cols;
            for(int j = 0; j < 9; j++){
                char c = board[j][i];
                if (c != '.'){
                    if(cols.find(c) != cols.end())
                        return false;
                    cols.insert(c);
                }
            }
        }

        vector<unordered_set<char>> boxes(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c != '.'){
                    int boxIndex = (i/3)*3 + (j/3);
                    if(boxes[boxIndex].find(c) != boxes[boxIndex].end()){
                        return false;
                    }
                    boxes[boxIndex].insert(c);
                }
            }
        }
        return true;
    }
};
