// Question Link: https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int numOfProvinces = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[i][i] == 1) {
                // Mark current node as visited
                isConnected[i][i] = 0;
                bfs(isConnected, i);
                numOfProvinces++;
            }
        }
        return numOfProvinces;
    }
    
    void bfs(vector<vector<int>> &isConnected, int node) {
        queue<int> todo;
        todo.push(node);
        while (!todo.empty()) {
            int cur = todo.front();
            todo.pop();
            for (int i = 0; i < isConnected[cur].size(); i++) {
                if (isConnected[cur][i] == 1 && isConnected[i][i] == 1) {
                    todo.push(i);
                    // Mark the cell as visited
                    isConnected[cur][i] = 0;
                    isConnected[i][cur] = 0;
                    isConnected[i][i] = 0;
                    // Province/Connection found
                }
            }
        }
    }
};