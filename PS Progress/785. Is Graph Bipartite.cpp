// Question Link: https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> A, B;
        for (int i = 0; i < graph.size(); i++) {
            if (B.find(i) == B.end() && A.find(i) == A.end()) {
                bool result = helper(graph, i, A, B);
                if (result == false) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool helper(vector<vector<int>> &graph, int current, unordered_set<int> &A, unordered_set<int> &B) {
        A.insert(current);
        for (int &child : graph[current]) {
            if (A.find(child) != A.end()) {
                return false;
            }
            if (B.find(child) == B.end()) {
                B.insert(child);
                if (helper(graph, child, B, A) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};