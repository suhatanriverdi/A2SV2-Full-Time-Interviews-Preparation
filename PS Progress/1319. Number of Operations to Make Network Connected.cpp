// Question Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        // Build undirected graph
        for (vector<int> &c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        int numberOfNetworks = 0, numberOfconnections = connections.size();
        // Get number of connected computer groups
        vector<bool> seen(n, false);
        for (int curNode = 0; curNode < graph.size(); curNode++) {
            if (seen[curNode] == false) {
                numberOfNetworks++;
                dfs(curNode, graph, seen);
            }
        }
        // If we have (n - 1) connections, there is a way to connect all computers
        if (numberOfconnections >= (n - 1)) {
            return numberOfNetworks - 1;
        }
        return -1;
    }
    
    void dfs(int cur, vector<vector<int>> &graph, vector<bool> &seen) {
        seen[cur] = true;
        for (int &neighbor : graph[cur]) {
            if (seen[neighbor] == false) {
                dfs(neighbor, graph, seen);
            }
        }
    }
};