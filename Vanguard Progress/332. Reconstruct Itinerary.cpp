// Question Link: https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the directed graph
        unordered_map<string, vector<string>> graph;
        int numOfEdges = tickets.size();
        for (vector<string> &ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }
        
        for (auto &it : graph) {
            sort(begin(it.second), end(it.second));
        }
        
        vector<string> result;
        vector<string> path = { "JFK" };
        dfs("JFK", path, result, graph, numOfEdges);
        return result;
    }
    
    void dfs(string cur, vector<string> &path, vector<string> &result, unordered_map<string, vector<string>> &graph, int numOfEdges) {
        if (result.empty() == false) {
            return;
        }
        if (numOfEdges == 0) {
            result = path;
            return;
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            string neighbor = graph[cur][i];
            if (neighbor != "#") {
                // Mark the edge
                graph[cur][i] = "#";
                path.push_back(neighbor);
                dfs(neighbor, path, result, graph, numOfEdges - 1);
                // Backtrack
                graph[cur][i] = neighbor;
                path.pop_back();
            }   
        }
    }
};