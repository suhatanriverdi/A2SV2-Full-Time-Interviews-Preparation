// Question Link: https://leetcode.com/problems/largest-perimeter-triangle/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(begin(A), end(A), greater<>());
        for (int i = 2; i < A.size(); i++) {
            if (canBeTriangle(A[i], A[i - 1], A[i - 2])) {
                return A[i] + A[i - 1] + A[i - 2];
            }
        }
        return 0;
    }
    
    bool canBeTriangle(int a, int b, int c) {
        return (
            a < b + c && a > abs(b - c) &&
            b < a + c && b > abs(a - c) &&
            c < b + a && c > abs(b - a)
        );
    }
};