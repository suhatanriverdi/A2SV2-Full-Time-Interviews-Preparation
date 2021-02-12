// Question Link: https://leetcode.com/problems/jump-game-iii/

// DFS Solution
class Solution {
public:
    bool canReach(vector<int> &arr, int idx) {
        // Base case
        if (idx < 0 || idx >= arr.size() || arr[idx] == -1) {
            return false;
        }
        // Destination
        if (arr[idx] == 0) {
            return true;
        }
        // Mark current cell as visited
        int dist = arr[idx];
        arr[idx] = -1;
        return canReach(arr, idx + dist) || canReach(arr, idx - dist);
    }
};

// BFS
class Solution {
public:
    bool canReach(vector<int> &arr, int idx) {
        queue<int> todo; // {index}
        todo.push(idx);
        while (!todo.empty()) {
            int cur = todo.front();
            todo.pop();
            if (arr[cur] == 0) {
                return true;
            }
            int right = cur + arr[cur];
            int left = cur - arr[cur];
            if (right < arr.size() && arr[cur] != -1) {
                todo.push(right);
            }
            if (left >= 0 && left < arr.size() && arr[cur] != -1) {
                todo.push(left);
            }
            arr[cur] = -1;
        }
        return false;
    }
};