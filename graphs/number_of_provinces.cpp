/* BFS */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int total_provinces = 0;
        for(int i = 0; i < n; i++){
            if (!visited[i]){
                total_provinces += 1; 
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(int j = 0; j < n; j++){
                        if (isConnected[curr][j] == 1 && !visited[j]){
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }
        return total_provinces;
    }
};

/* DFS */
class Solution {
    void dfs(int n, vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        visited[i] = true;
        for(int j = 0; j < n; j++){
            if (isConnected[i][j] == 1 && !visited[j]){
                dfs(n, isConnected, visited, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int total = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if (!visited[i]){
                total += 1;
                dfs(n, isConnected, visited, i);
            }
        }
        return total;
    }
};
