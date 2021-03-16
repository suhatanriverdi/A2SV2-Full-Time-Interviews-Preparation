// Question Link: https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        queue<vector<int>> todo; // {index, dist}
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                todo.push({i, 0});
            }
        }
        int maxDist = 0;
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            maxDist = max(maxDist, cur[1]);
            int L = cur[0] - 1;
            if (L >= 0 && seats[L] == 0) {
                todo.push({L, cur[1] + 1});
                seats[L] = cur[1] + 1;
            }
            int R = cur[0] + 1;
            if (R < seats.size() && seats[R] == 0) {
                todo.push({R, cur[1] + 1});
                seats[R] = cur[1] + 1;
            }
        }
        return maxDist;
    }
};
