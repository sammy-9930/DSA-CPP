/*
Depth first search
Time complexity - O(v^2)
Space complexity - O(v^2) + O(v) + O(v) 
*/
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int& n, int src, vector<bool>& visited){
        for(int i = 0; i < n; i++){
            if(isConnected[src][i] == 1 && !visited[i]){
                visited[i] = true;
                dfs(isConnected, n, i, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int noOfProvinces = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                noOfProvinces++;
                dfs(isConnected, n, i, visited);
            }
        }
        return noOfProvinces;
    }
};

/*
Breadth first search
Time complexity - O(v^2)
Space complexity -  O(v^2) + O(v) + O(v)
*/
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
