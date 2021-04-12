// Question Link: https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size() + 1;
        vector<vector<int>> graph(N);
        vector<bool> seen(N, false);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            // Check if there is a cycle
            if (hasCycle(edge[0], graph, seen, -1)) {
                return edge;
            }
        }
        return { 1453 };
    }
    
    bool hasCycle(int cur, vector<vector<int>> &graph, vector<bool> &seen, int parent) {
        seen[cur] = true;
        bool cycle = false;
        for (int &neighbor : graph[cur]) {
            if (seen[neighbor] == false) {
                cycle |= hasCycle(neighbor, graph, seen, cur);
            }
            // Cycle found! Neighbor is visited and is not parent of cur
            else if (neighbor != parent) {
                return true;
            }
        }
        seen[cur] = false;
        return cycle;
    }
};