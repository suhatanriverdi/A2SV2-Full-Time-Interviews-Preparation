// Question Link: https://leetcode.com/problems/satisfiability-of-equality-equations

// Union Find(Disjoint Set) Solution
class Solution {
    int parent[26] = {0}, children[26] = {0};
public:
    bool equationsPossible(vector<string>& equations) {
        // Every node is parent of itself at the beginning
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        // Create sets by looking '=='
        for (string &equ : equations) {
            int A = equ[0] - 'a';
            int B = equ[3] - 'a';
            char sign = equ[1];
            if (sign == '=') {
                union_sets(A, B);
            }
        }
        // Check equality by looking '!='
        for (string &equ : equations) {
            int A = equ[0] - 'a';
            int B = equ[3] - 'a';
            char sign = equ[1];
            if (sign == '!' && find_set(A) == find_set(B)) {
                return false;
            }
        }
        return true;
    }
    
    // Finds the parent of given node, climbs up to the ancestors
    int find_set(int v) {
        if (v == parent[v]) {
            return v;
        }
        return find_set(parent[v]);
    }
    
    // Merges two sets by matching their parents
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
        }
    }
};

// DFS Solution
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
