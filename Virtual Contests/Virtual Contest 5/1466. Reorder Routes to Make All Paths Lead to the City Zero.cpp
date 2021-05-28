// Question Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Build undirected graph first
        vector<unordered_set<int>> unGraph(n);
        vector<unordered_set<int>> realEdges(n);
        for (vector<int> &conn : connections) {
            unGraph[conn[0]].insert(conn[1]);
            unGraph[conn[1]].insert(conn[0]);
            // Real edges
            realEdges[conn[0]].insert(conn[1]);
        }
        int answer = 0;
        queue<int> todo;
        vector<bool> seen(n, false);
        seen[0] = true;
        todo.push(0);
        while (!todo.empty()) {
            int cur = todo.front();
            todo.pop();
            for (int neigh : unGraph[cur]) {
                if (seen[neigh] == false) {
                    // Check if there is a road from neigh to me
                    if (realEdges[neigh].find(cur) == realEdges[neigh].end()) {
                        answer++;
                    }
                    seen[neigh] = true;
                    todo.push(neigh);
                }
            }
        }
        
        return answer;
    }
};