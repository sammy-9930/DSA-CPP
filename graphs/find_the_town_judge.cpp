/*
indegree and outdegree 
time : O(V + E), space : O(V)
V - no of vertices , E - no of edges 
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> incoming(n+1, 0);
        vector<int> outgoing(n+1, 0);

        for (auto& t : trust){
            outgoing[t[0]] += 1;
            incoming[t[1]] += 1;
        }

        for (int i = 1; i <= n; i++){
            if (outgoing[i] == 0 && incoming[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};

/*
using one array
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n+1, 0);

        for (auto& t: trust){
            score[t[0]] -= 1;
            score[t[1]] += 1;
        }

        for (int i = 1; i <= n; i++){
            if (score[i] == n - 1){
                return i;
            }
        }
        return -1;
    }
};