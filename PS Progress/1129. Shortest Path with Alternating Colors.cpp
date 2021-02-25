// Question Link: https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<pair<int, int>>> adjList(n);
        // Red edges 0
        for (vector<int> &r : red_edges) {
            adjList[r[0]].push_back({r[1], 0});
        }
        // Blue edges 1
        for (vector<int> &b : blue_edges) {
            adjList[b[0]].push_back({b[1], 1});
        }
        vector<vector<int>> seen(n, vector<int>(2, 0)); // {node, with which color we came}
        vector<int> result(n, -1);
        queue<vector<int>> todo; // {node, latest edge color 1:B 0:R, dist}
        todo.push({0, 1, 0});
        todo.push({0, 0, 0});
        seen[0][0] = 1; // For 0, Make both Red and Blue Edges are visited
        seen[0][1] = 1;
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            for (pair<int, int> &child : adjList[cur[0]]) {
                // If it is Alternating & Red/Blue edge unvisited
                if (seen[child.first][child.second] == 0 && child.second != cur[1]) {
                    todo.push({child.first, child.second, cur[2] + 1});
                    result[child.first] = (result[child.first] == -1 ? cur[2] + 1 : result[child.first]);
                    seen[child.first][child.second] = 1;
                }
            }
        }
        result[0] = 0;
        return result;
    }
};