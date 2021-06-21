// Question Link: https://leetcode.com/problems/smallest-string-with-swaps/

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        int len = s.size();
        if (len == 0) {
            return s;
        }
        
        // Build the undirected adjacency list graph
        vector<vector<int>> graph(len);
        vector<bool> seen(len, false);
        for (vector<int> &pair: pairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        // For each component in the graph
        for (int cur = 0; cur < len; cur++) {
            if (seen[cur] == false) {
                vector<int> indices;
                string sortedPart = "";
                // Get the indices
                dfs(cur, indices, graph, seen);
                // Sort the string
                for (int &idx : indices) {
                    sortedPart += s[idx];
                }
                sort(sortedPart.begin(), sortedPart.end());
                sort(indices.begin(), indices.end());
                int i = 0;
                for (int &idx : indices) {
                    s[idx] = sortedPart[i++];
                }
            }
        }
        return s;
    }
    
    void dfs(int cur, vector<int> &indices, vector<vector<int>> &graph, vector<bool> &seen) {
        seen[cur] = true;
        indices.push_back(cur);
        for (int &neigh : graph[cur]) {
            if (seen[neigh] == false) {
                dfs(neigh, indices, graph, seen);
            }
        }
    }
};