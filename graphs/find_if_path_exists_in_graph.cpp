/*
BFS - adjacency matrix 
time: O(v^2) , space: O(v^2) matrix + o(v) queue + o(v) visited
*/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<bool> visited(n, false);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if (curr == destination)
                return true;
            for(int i = 0; i < n; i++){
                if (graph[curr][i] == 1 && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return false;
    }
};

/*
DFS - adjacency matrix 
time: O(v^2) , space: O(v^2) matrix + o(v) queue + o(v) visited
*/
class Solution {
public:
    bool dfs(int n, vector<vector<int>>& graph, vector<bool>& visited, int source, int destination){
        if (source == destination)
            return true; 
        visited[source] = true;
        for(int i = 0; i < n; i++){
            if (graph[source][i] == 1 && !visited[i]){
                if (dfs(n, graph, visited, i, destination))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<bool> visited(n, false);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        return dfs(n, graph, visited, source, destination);
    }
};

/*
BFS - adjacency list 
time: O(v + E) , space: O(v + E) matrix + o(v) queue + o(v) visited
*/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if (curr == destination){
                return true;
            }
            for(auto neighbour: graph[curr]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return false;
    }
};


/*
DFS - adjacency list 
time: O(v + E) , space: O(v + E) matrix + o(v) queue + o(v) visited
*/
class Solution {
public:
    bool dfs(int n, vector<vector<int>>& graph, vector<bool>& visited, int source, int destination){
        if (source == destination){
            return true;
        }
        visited[source] = true;
        for(auto neighbour: graph[source]){
            if(!visited[neighbour]){
                if (dfs(n, graph, visited, neighbour, destination)){
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return dfs(n, graph, visited, source, destination);
    }
};