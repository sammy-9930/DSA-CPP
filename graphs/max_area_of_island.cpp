class Solution {
public:
    int rows, cols;
    int bfs(int r, int c, vector<vector<int>>& grid){
        int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = 0;
        int cur_area = 1;

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto d: directions){
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx >= 0 && dy >= 0 && dx < rows && dy < cols && grid[dx][dy] == 1){
                    q.push({dx, dy});
                    grid[dx][dy] = 0;
                    cur_area += 1;
                }
            }
        }
        return cur_area; 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int max_size = 0;
        for (int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if (grid[r][c] == 1){
                    max_size = max(max_size, bfs(r, c, grid));
                }
            }
        }
        return max_size;
    }
};