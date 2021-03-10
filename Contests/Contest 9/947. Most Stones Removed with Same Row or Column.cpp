// Question Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // Build adjacency graph for DFS, think of each stone has ID
        int n = stones.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int maxStones = 0;
        vector<bool> seen(n, false);
        for (int curNode = 0; curNode < n; curNode++) {
            if (seen[curNode] == false) {
                int count = 0;
                dfs(curNode, graph, seen, count);
                maxStones += count;
            }
        }
        return maxStones;
    } 
    
    void dfs(int cur, vector<vector<int>> &graph, vector<bool> &seen, int &count) {
        seen[cur] = true;
        for (int &neighbor : graph[cur]) {
            if (seen[neighbor] == false) {
                count++;
                dfs(neighbor, graph, seen, count);
            }
        }
    }
};
