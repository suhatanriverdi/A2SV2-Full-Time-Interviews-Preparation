// Question Link: https://leetcode.com/problems/minimum-operations-to-make-array-equal/

class Solution {
public:
    int minOperations(int n) {
        vector<int> A(n, 0);
        for (int i = 0; i < n; i++) {
            A[i] = (i * 2) + 1;
        }
        // Take elements from both ends
        int minOps = 0;
        for (int front = 0, back = n - 1; front < back; front++, back--) {
            minOps += (A[back] - A[front]) / 2;
        }
        return minOps;
    }
};