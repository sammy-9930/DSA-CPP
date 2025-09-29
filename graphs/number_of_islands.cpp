/*
BFS 
time: o(mn), space: o(mn)
*/
class Solution {
public:
    void bfs(int r, int c, vector<vector<bool>>& visited, const vector<vector<char>>& grid, int rows, int cols){
        queue<pair<int,int>> q;
        q.push({r, c});
        visited[r][c] = true;

        const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(const auto& dir : directions){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == '1' && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islands = 0; 
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == '1' && visited[i][j] == false){
                    bfs(i, j, visited, grid, rows, cols);
                    islands += 1;
                }
            }
        }
        return islands;
    }
};

/*
DFS
time: o(mn), space: o(mn)
*/
class Solution {
public:
    int rows, cols;
    void dfs(int r, int c, vector<vector<char>>& grid){
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
            return; 
        
        grid[r][c] = '0';

        dfs(r+1, c, grid);
        dfs(r, c+1, grid);
        dfs(r-1, c, grid);
        dfs(r, c-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int islands = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if (grid[r][c] == '1'){
                    dfs(r, c, grid);
                    islands += 1;
                }
            }
        }
        return islands;
    }
};