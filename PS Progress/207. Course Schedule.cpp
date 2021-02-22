// Question Link: https://leetcode.com/problems/course-schedule/

// BFS Solution
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> edgeCounts(numCourses, 0); // {node, incoming edges}
        queue<int> todo; // nodes that has no incoming edges, meaning starting points
        // Build the adjacency list
        for (vector<int> &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            // Count the incoming edges
            edgeCounts[p[0]]++;
        }
        // Find the nodes/roots that has no incoming edges
        for (int node = 0; node < edgeCounts.size(); node++) {
            // If a nodes has no incoming edge, this is a root
            if (edgeCounts[node] == 0) {
                todo.push(node);
            }
        }
        // If there is no any root node
        if (todo.empty()) {
            return false;
        }
        // Start BFS
        int processedCourseCount = 0; // Num of roots at the beginning
        while (!todo.empty()) {
            int cur = todo.front();
            todo.pop();
            // If we hit to 0 edge count, we don't need that node anymore
            if (edgeCounts[cur] == 0) {
                processedCourseCount++;
            } 
            for (int &neighbor : graph[cur]) {
                // Decrease our edge count
                edgeCounts[neighbor]--;
                if (edgeCounts[neighbor] == 0) {
                    todo.push(neighbor);
                }
            }
        }
        return (processedCourseCount == numCourses);
    }
};

// DFS Solution
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<bool> seen(numCourses, false), cycle(numCourses, false);
        // Build the adjacency list
        for (vector<int> &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        // Start DFS for each Node
        stack<int> topoSort;
        bool hasCycle = false;
        for (int node = 0; node < graph.size(); node++) {
            if (seen[node] == false) {
                dfs(graph, node, seen, topoSort, hasCycle, cycle);
            }
        }
        int size = topoSort.size();
        return (numCourses == size && !hasCycle);
    }
    
    void dfs(vector<vector<int>> &graph, int cur, vector<bool> &seen, stack<int> &topoSort, bool &hasCycle, vector<bool> &cycle) {
        seen[cur] = true;
        cycle[cur] = true;
        for (int &child : graph[cur]) {
            if (seen[child] == false) {
                dfs(graph, child, seen, topoSort, hasCycle, cycle);
            }
            else if (cycle[child] == true) {
                hasCycle = true;
                return;
            }
        }
        cycle[cur] = false; // This is for cycle detection
        topoSort.push(cur);
    }
};
