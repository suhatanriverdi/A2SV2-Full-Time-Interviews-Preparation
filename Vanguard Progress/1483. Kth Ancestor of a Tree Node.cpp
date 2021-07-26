// Question https://leetcode.com/problems/kth-ancestor-of-a-tree-node

class TreeAncestor {
private:
    vector<vector<int>> graph;
    vector<vector<int>> rootToLeafPaths;
    vector<vector<int>> nodeIndex;
public:
    TreeAncestor(int n, vector<int> &parent) {
        // Build the directed graph
        graph.resize(n);
        nodeIndex.resize(n);
        for (int i = 1; i < n; i++) { // O(N)
            graph[parent[i]].push_back(i);
        }
        // Run DFS
        vector<int> path;
        int curPathIndex = 0;
        dfs(0, graph, path, curPathIndex, 0);
    }
    
    void dfs(int cur, vector<vector<int>> &graph, vector<int> &path, int &curPathIndex, int curNodeIndex) { // O(N)
        path.push_back(cur);
        // Store node index to access it later on
        nodeIndex[cur] = {curPathIndex, curNodeIndex};
        // For all children
        for (int &child : graph[cur]) {
            dfs(child, graph, path, curPathIndex, curNodeIndex + 1);
        }
        // Backtracking, store all root to leaf paths
        if (graph[cur].empty()) {
            rootToLeafPaths.push_back(path);
            curPathIndex++;
        }
        path.pop_back();
    }
    
    int getKthAncestor(int node, int k) {
        int ithNode = nodeIndex[node][1];
        int kthAncestor = ithNode - k;
        if (kthAncestor < 0) {
            return -1;
        }
        // Get the path where node is in
        int pathIndex = nodeIndex[node][0];
        return rootToLeafPaths[pathIndex][kthAncestor];
    }
};
