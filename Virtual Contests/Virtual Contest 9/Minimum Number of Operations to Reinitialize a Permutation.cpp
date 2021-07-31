// Question Link: https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

class Solution {
public:
    int reinitializePermutation(int n) {
        if (n == 2) {
            return 1;
        }
        vector<int> A(n, 0);
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }
        
        int cnt = 1;
        op(A, n);
        
        while (A[1] != 1 && A[n - 2] != n - 2) {
            op(A, n);
            cnt++;
        }
        return cnt;
    }
    
    void op(vector<int> &A, int &n) {
        for (int i = 0; i < n; i++) {
            if (A[i] & 1) {
                A[i] = (n / 2) + ((A[i] - 1) / 2);
            }
            else {
                A[i] = A[i] / 2;
            }
        }
    }
};