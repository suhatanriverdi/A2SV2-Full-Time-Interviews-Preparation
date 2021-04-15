// Question Link: https://leetcode.com/problems/minimum-sideway-jumps/

// DP Solution 344ms
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int minSideJumps = 0, N = obstacles.size();
        vector<int> dp = {1, 0, 1}; // minimum side jumps to reach line_i {line1, line2, line3}
        for (int i = 1; i < N; i++) {
            // First try to go ahead
            for (int l = 0; l <= 2; l++) {
                dp[l] = (obstacles[i] - 1 == l ? 500005 : dp[l]);
            }
            // Update side jumps
            for (int l = 0; l <= 2; l++) {
                // If not obstacle
                if (obstacles[i] - 1 != l) {
                    // Up side jump
                    if ((l - 1) >= 0 && obstacles[i] - 1 != l - 1) {
                        dp[l - 1] = min(dp[l - 1], dp[l] + 1);
                    }
                    if ((l - 2) >= 0 && obstacles[i] - 1 != l - 2) {
                        dp[l - 2] = min(dp[l - 2], dp[l] + 1);
                    }
                    // Down side jump
                    if ((l + 1) <= 2 && obstacles[i] - 1 != l + 1) {
                        dp[l + 1] = min(dp[l + 1], dp[l] + 1);
                    }
                    if ((l + 2) <= 2 && obstacles[i] - 1 != l + 2) {
                        dp[l + 2] = min(dp[l + 2], dp[l] + 1);
                    }
                }
            }
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};

// BFS Solution 1652ms
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int N = obstacles.size();
        bool seen[500001][3] = {false};
        queue<vector<int>> todo; // {line number (i), point(j), number of side jumps}
        todo.push({1, 0, 0}); // {i, j, sideJumps}
        seen[0][1] = true;
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            // Check if we reached to destination(the last column, N)
            if (cur[1] == N - 1) {
                return cur[2];
            }
            int goAhead = cur[1] + 1;
            // Try to go ahead first as much as we can
            if (goAhead < N && !seen[goAhead][cur[0]] && (obstacles[goAhead] - 1) != cur[0]) {
                todo.push({cur[0], goAhead, cur[2]});
                seen[goAhead][cur[0]] = true;
            }
            else {
                // Then, try to do a side jump
                int upJump, downJump;
                for (int i = 1; i < 3; i++) {
                    // If up side jump is valid
                    upJump = cur[0] - i;
                    if (upJump >= 0 && !seen[cur[1]][upJump] && (obstacles[cur[1]] - 1) != upJump) {
                        todo.push({upJump, cur[1], cur[2] + 1});
                        seen[cur[1]][upJump] = true;
                    }
                    // If down side jump is valid
                    downJump = cur[0] + i;
                    if (downJump <= 2 && !seen[cur[1]][downJump] && (obstacles[cur[1]] - 1) != downJump) {
                        todo.push({downJump, cur[1], cur[2] + 1});
                        seen[cur[1]][downJump] = true;
                    }
                }
            }
        }
        return 0;
    }
};