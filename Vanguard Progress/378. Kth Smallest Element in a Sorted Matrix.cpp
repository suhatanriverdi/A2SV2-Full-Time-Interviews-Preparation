// Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// Using PQ Short & Better Version
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> sorted;
        for (vector<int> &r : matrix) {
            sorted.insert(end(sorted), begin(r), end(r));
        }
        sort(begin(sorted), end(sorted));
        return sorted[k - 1];
    }
};

// Using PQ Initial Version
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = matrix.size();
        vector<vector<int>> directions = { {0, 1}, {1, 0} };
        priority_queue<vector<int>> pq;
        pq.push({ -1 * matrix[0][0], 0, 0 });
        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            k--;
            if (k == 0) {
                return -1 * cur[0];
            }
            // Check left and down only
            for (vector<int> &dir : directions) {
                int nx = cur[1] + dir[0];
                int ny = cur[2] + dir[1];
                if (nx < N && ny < N && matrix[nx][ny] != INT_MAX) {
                    pq.push({ -1 * matrix[nx][ny], nx, ny });
                    matrix[nx][ny] = INT_MAX;
                }
            }
        }
        return 1453;
    }
};