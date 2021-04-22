// Question Link: https://leetcode.com/problems/network-delay-time

/*
BFS Priority Queue Solution
In classical BFS, since we use normal queue and we process each node only once the time complexity is O(V + E) (If the graps has way more edges than nodes than O(E), bigger term dominates), but here we use priority queue to sort elements with respect to their way costs, since there can be at most E incoming edges to one single node meaning that our graph can be edge weighted, the maximum size our priority queue can reach to is number of Edges which will sort not N but E elements, thus;

Time Complexity: O(E log E)
Space Complexity: E - V
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (vector<int> &time : times) {
            graph[time[0]].push_back({time[2], time[1]});
        }
        vector<int> nodeArrivalCost(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> todo;
        set<pair<int, int>> seen = {{0, k}}; // {Weight, Node}
        todo.push({0, k});
        while (!todo.empty()) {
            pair<int, int> cur = todo.top();
            todo.pop();
            nodeArrivalCost[cur.second] = min(nodeArrivalCost[cur.second], cur.first);
            for (pair<int, int> &child : graph[cur.second]) {
                if (seen.find(child) == seen.end()) {
                    seen.insert({child.first, child.second});
                    todo.push({child.first + cur.first, child.second});
                }
            }
        }
        int result = -1;
        for (int i = 1; i <= n; i++) {
            if (nodeArrivalCost[i] == INT_MAX) {
                return -1;
            }
            result = max(result, nodeArrivalCost[i]);
        }
        return result;
    }
};