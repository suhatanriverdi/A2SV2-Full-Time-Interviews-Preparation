// Question Link: https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        vector<vector<char>> graph(26); // {node, neighbours}
        for (string &e : equations) {
            if (e[1] == '=') {
                graph[e[0] - 'a'].push_back(e[3]);
                graph[e[3] - 'a'].push_back(e[0]);
            }
        }
        for (string &e : equations) {
            if (e[1] == '!') {
                vector<bool> seen(26, false);
                bool isThereAPath = hasPath(e[0], e[3], graph, seen);
                if (isThereAPath == true) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool hasPath(char cur, char dest, vector<vector<char>> &graph, vector<bool> &seen) {
        seen[cur - 'a'] = true; // Mark current node as visited
        bool result = false;
        // Path found
        if (cur == dest) {
            return true;
        }
        // Look for other neighbors
        for (char neigh : graph[cur - 'a']) {
            if (seen[neigh - 'a'] == false) {
                result |= hasPath(neigh, dest, graph, seen);
            }
        }
        return result;
    }
};