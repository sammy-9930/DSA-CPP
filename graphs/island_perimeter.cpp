/*
DFS
time: O(m*n), space: O(m*n)
m - no of rows, n - no of cols 
*/
class Solution {
private:
    vector<vector<bool>> visited;
    vector<vector<int>> grid;
    int rows, cols;

    int dfs(int i, int j){
        if (i >= rows ||
            j >= cols || 
            i < 0 || j < 0 ||
            grid[i][j] == 0){
                return 1;
            }
        
        if (visited[i][j]){
            return 0;
        }

        visited[i][j] = true;

        return dfs(i, j + 1) + 
               dfs(i + 1, j) + 
               dfs(i - 1, j) + 
               dfs(i, j - 1);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid = grid;
        rows = grid.size();
        cols = grid[0].size(); 
    
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == 1){
                    return dfs(i, j);
                }
            }
        }
        return 0;
    }
};