class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // validate rows 
        for (int i = 0; i < 9; i++){
            unordered_set<char> set;
            for(int j = 0; j < 9; j++){
                char item = board[i][j];
                if (set.count(item))
                    return false; 
                if (item != '.')
                    set.insert(item);
            }
        }

        for (int i = 0; i < 9; i++){
            unordered_set<char> set;
            for (int j = 0; j < 9; j++){
                char item = board[j][i];
                if (set.count(item))
                    return false; 
                if (item != '.')
                    set.insert(item);
            }
        }

        //valide 3x3 subgrids 
        vector<vector<int>> starts = {{0,0}, {0,3}, {0,6},
                                     {3,0}, {3,3}, {3,6},
                                     {6,0}, {6,3}, {6,6}};
        
        for (auto& start: starts){
            unordered_set<char> set;
            for (int row = start[0]; row < start[0] + 3; row++){
                for (int col = start[1]; col < start[1] + 3; col++){
                    char item = board[row][col];
                    if (set.count(item))
                        return false; 
                    if (item != '.')
                        set.insert(item);
                }
            }
        }
        return true;
    }
};