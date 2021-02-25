// Question Link: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        // Build the directed graph
        for (vector<int> p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        vector<int> topoSort;
        // Visited and cycle detection arrays
        vector<bool> seen(numCourses, false), cycle(numCourses, false);
        bool hasCycle = false;
        // Run topo search for each node
        for (int curNode = 0; curNode < numCourses; curNode++) {
            if (seen[curNode] == false) {
                dfs(curNode, seen, cycle, graph, topoSort, hasCycle);
            }
        }
        reverse(begin(topoSort), end(topoSort));
        return (hasCycle ? vector<int>() : topoSort);
    }
    
    void dfs(int curNode, vector<bool> &seen, vector<bool> &cycle, vector<vector<int>> &graph, vector<int> &topoSort, bool &hasCycle) {
        seen[curNode] = true; // mark current node as visited
        cycle[curNode] = true; // Cycle detection
        for (int &child : graph[curNode]) {
            if (seen[child] == false) {
                dfs(child, seen, cycle, graph, topoSort, hasCycle);
            }
            // If there is a cycle
            if (cycle[child] == true) {
                hasCycle = true;
                return;
            }
        }
        cycle[curNode] = false; // Backtrack for cycle detection
        topoSort.push_back(curNode);
    }
};