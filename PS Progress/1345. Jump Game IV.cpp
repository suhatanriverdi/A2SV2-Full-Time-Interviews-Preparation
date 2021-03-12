// Question Link: https://leetcode.com/problems/jump-game-iv/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int N = arr.size();
        if (N == 1) {
            return 0;
        }
        unordered_map<int, vector<int>> graph; // {value, indices}
        for (int i = 1; i < N; i++) {
            graph[arr[i]].push_back(i);
        }
        
        queue<vector<int>> todo; // {idx, steps}
        todo.push({0, 0});
        vector<bool> seen(N, false); // Mark starting point as visited
        seen[0] = true;
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            if (cur[0] == N - 1) {
                return cur[1];
            }
            // Check right  i + 1
            int nR = cur[0] + 1;
            if (nR < N && seen[nR] == false) {
                todo.push({nR, cur[1] + 1});
                seen[nR] = true;
            }
            int nL = cur[0] - 1;
            // Check left  i - 1
            if (nL >= 0 && seen[nL] == false) {
                todo.push({nL, cur[1] + 1});
                seen[nL] = true;
            }
            for (int &neigh : graph[arr[cur[0]]]) {
                if (seen[neigh] == false) {
                    todo.push({neigh, cur[1] + 1});
                    seen[neigh] = true;
                }
            }
            graph.erase(arr[cur[0]]);
        }
        return N - 1;
    }
};
