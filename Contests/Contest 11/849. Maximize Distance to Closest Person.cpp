// Question Link: https://leetcode.com/problems/maximize-distance-to-closest-person/

// Two Pointer Solution
class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        vector<int> curRange;
        int maxDist = 0, dist;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 0) {
                curRange = getMaxZeroSubArray(i, seats);
                int end = curRange[1];
                int begin = curRange[0];
                int curLen = curRange[1] - curRange[0] + 1;
                // If we are in between 1's
                if ((end + 1 < seats.size() && seats[end + 1] == 1) &&
                   (begin - 1 >= 0 && seats[begin - 1] == 1)) {
                    dist = curLen / 2 + (curLen % 2);
                    maxDist = max(maxDist, dist);
                } else {
                    maxDist = max(maxDist, curLen);
                }
                i = curRange[1];
            }
        }
        return maxDist;
    }

    vector<int> getMaxZeroSubArray(int idx, vector<int> &seats) {
        int start = idx;
        for (; idx < seats.size() && seats[idx] == 0; idx++) {};
        idx--;
        return {start, idx};
    }
};

// BFS Solution
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
