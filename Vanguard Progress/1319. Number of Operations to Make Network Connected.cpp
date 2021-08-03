// Question Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int numberOfEdges = connections.size();
        if (numberOfEdges < n - 1) {
            return -1;
        }
        
        vector<vector<int>> graph(n);
        for (vector<int> &connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        
        int numberOfSubgraphs = 0;
        vector<bool> seen(n, false);
        for (int node = 0; node < n; node++) {
            if (!seen[node]) {
                dfs(node, graph, seen);
                numberOfSubgraphs++;
            }
        }
        
        return numberOfSubgraphs - 1;
    }
    
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &seen) {
        seen[node] = true;
        for (int &neighbor : graph[node]) {
            if (!seen[neighbor]) {
                dfs(neighbor, graph, seen);
            }
        }
    }
};