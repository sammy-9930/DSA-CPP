class Solution {
public:
    bool isValid(int row, int col, vector<string>& board, int n){
        // horizontal 
        for(int c = col; c >= 0; c--){
            if (board[row][c] == 'Q')
                return false;
        }

        // diagonal - upper left 
        for (int r = row, c = col; r >=0 && c >= 0; r--, c--)
            if (board[r][c] == 'Q')
                return false;

        // diagonal - upper right 
        for (int r = row, c = col; r < n && c >= 0; r++, c--)
            if (board[r][c] == 'Q')
                return false;

        return true; 
    }

    void helper(int col, vector<string>& board, vector<vector<string>>& res, int n){
        // base condition
        if (col == n){
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row ++){
            if (isValid(row, col, board, n)){
                board[row][col] = 'Q';
                helper(col+1, board, res, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i ++)
            board[i] = s;
        helper(0, board, res, n);
        return res; 
    }
};