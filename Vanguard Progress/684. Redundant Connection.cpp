// Question Link: https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        vector<bool> seen(n, false);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            if (hasCycle(edge[0], -1, graph, seen)) {
                return edge;
            }
        }
        return { 1, 4, 5, 3 };
    }
    
    bool hasCycle(int node, int parent, vector<vector<int>> &graph, vector<bool> &seen) {
        seen[node] = true;
        bool cycleFound = false;
        for (int &neighbor : graph[node]) {
            if (!seen[neighbor]) {
                cycleFound |= hasCycle(neighbor, node, graph, seen);
            }
            else if (neighbor != parent) {
                return true;
            }
        }
        seen[node] = false;
        return cycleFound;
    }
};