// Question Link: https://leetcode.com/problems/loud-and-rich

// DFS with memoization
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int N = quiet.size();
        vector<vector<int>> graph(N); // {node, neighbor}
        for (vector<int> &rich : richer) {
            graph[rich[1]].push_back({rich[0]});
        }
        vector<int> result(N, INT_MAX);
        for (int cur = 0; cur < graph.size(); cur++) {
            unordered_set<int> seen;
            if (seen.find(cur) == seen.end()) {
                int theleastQuietPerson = cur;
                dfs(cur, theleastQuietPerson, graph, seen, quiet, result);
                result[cur] = theleastQuietPerson;
            }
        }
        return result;
    }
    
    void dfs(int cur, int &leastQuietPerson, vector<vector<int>> &graph, unordered_set<int> &seen, vector<int> &quiet, vector<int> &result) {
        // If we calculate the result for current node before
        if (result[cur] != INT_MAX) {
            if (quiet[result[cur]] < quiet[leastQuietPerson]) {
                leastQuietPerson = result[cur];
            }
            return;
        }
        // Update the quietest person on the way
        if (quiet[cur] < quiet[leastQuietPerson]) {
            leastQuietPerson = cur;
        }
        seen.insert(cur);
        for (int &neigh : graph[cur]) {
            if (seen.find(neigh) == seen.end()) {
                dfs(neigh, leastQuietPerson, graph, seen, quiet, result);
            }
        }
    }
};

// Without Memoization
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int N = quiet.size();
        vector<vector<int>> graph(N); // {node, neighbor}
        for (vector<int> &rich : richer) {
            graph[rich[1]].push_back({rich[0]});
        }
        vector<int> result(N, INT_MAX);
        for (int cur = 0; cur < graph.size(); cur++) {
            unordered_set<int> seen;
            if (seen.find(cur) == seen.end()) {
                int curQuietest = cur;
                dfs(cur, curQuietest, graph, seen, quiet);
                result[cur] = curQuietest;
            }
        }
        return result;
    }
    
    void dfs(int cur, int &quietestNode, vector<vector<int>> &graph, unordered_set<int> &seen, vector<int> &quiet) {
        seen.insert(cur);
        // Update the quietest person on the way
        if (quiet[cur] < quiet[quietestNode]) {
            quietestNode = cur;
        }
        for (int &neigh : graph[cur]) {
            if (seen.find(neigh) == seen.end()) {
                dfs(neigh, quietestNode, graph, seen, quiet);
            }
        }
    }
};
