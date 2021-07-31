// Question Link: https://leetcode.com/problems/loud-and-rich/

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        for (vector<int> &r : richer) {
            graph[r[1]].push_back(r[0]);
        }        
        
        vector<int> answer(n, -1);
        for (int cur = 0; cur < n; cur++) {
            dfs(cur, graph, quiet, answer);
        }
        
        return answer;
    }
    
    int dfs(int cur, vector<vector<int>> &graph, vector<int> &quiet, vector<int> &answer) {
        int leastQuietPerson = cur;
        for (int &richer : graph[cur]) {
            // Memoization
            int ret = (answer[richer] != -1) ? answer[richer] : dfs(richer, graph, quiet, answer);
            if (quiet[ret] < quiet[leastQuietPerson]) {
                leastQuietPerson = ret;
            }
        }
        answer[cur] = leastQuietPerson;
        return leastQuietPerson;
    }
};