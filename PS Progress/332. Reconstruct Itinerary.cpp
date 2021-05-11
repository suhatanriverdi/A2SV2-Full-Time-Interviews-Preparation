// Question Link: https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // multiset -> we can have multiple same tickets: ["TIA","ANU"], ["TIA","ANU"]
        unordered_map<string, multiset<string>> graph;
        unordered_map<string, int> seen;
        for (vector<string> &ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
            // count number of edges
            seen[ticket[0] + ticket[1]]++;
        }
        vector<string> path = { "JFK" }, result;
        dfs(path, result, "JFK", graph, seen, tickets.size());
        return result;
    }
    
    void dfs(vector<string> &path, vector<string> &result, string cur, unordered_map<string, multiset<string>> &graph, unordered_map<string, int> &seen, int edgesCount) {
        if (result.empty() == false) {
            return;
        }
        // If we visited each node once and only once means that we have found the correct result
        if (edgesCount == 0) {
            result = path;
            return;
        }
        for (auto child : graph[cur]) {
            if (seen[cur + child] > 0) {
                path.push_back(child);
                seen[cur + child]--;
                // Recursion
                dfs(path, result, child, graph, seen, edgesCount - 1);
                // Backtracking
                seen[cur + child]++;
                path.pop_back();
            }
        }
    }
};