// Question Link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // Build graph
        vector<vector<int>> graph(n);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        // Keep max heap to start from far nodes from 0
        priority_queue<vector<int>> todo; // {layer, node}
        vector<bool> seen(n, false);
        vector<int> layer(n, 0);
        // Get each layer of nodes to keep going up
        layer[0] = 1;
        getLayers(0, graph, layer);
        // Keep track of apples beforehand, we will run BFS from apples
        for (int i = 1; i < hasApple.size(); i++) {
            if (hasApple[i] == 1) {
                todo.push({layer[i], i});
                seen[i]  = true;
            }
        }
        // Mark 0 as visited
        seen[0] = true;
        // Keep track of the distances
        vector<int> dists(n, 0);
        // Run BFS
        while (!todo.empty()) {
            vector<int> cur = todo.top();
            todo.pop();
            for (int &neighbor : graph[cur[1]]) {
                if (seen[neighbor] == false) {
                    todo.push({layer[neighbor], neighbor});
                    seen[neighbor] = true;
                }
                if (layer[cur[1]] > layer[neighbor]) {
                    dists[neighbor] += dists[cur[1]] + 2;
                }
            }
        }
        return dists[0];
    }
    
    void getLayers(int cur, vector<vector<int>> &graph, vector<int> &layer) {
        for (int &neighbor : graph[cur]) {
            if (layer[neighbor] == 0) {
                layer[neighbor] = layer[cur] + 1;
                getLayers(neighbor, graph, layer);
            }
        }
    }
};
