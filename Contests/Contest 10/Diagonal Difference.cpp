// Question Link: https://www.hackerrank.com/challenges/diagonal-difference/problem

int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size();
    if (n < 0) {
        return 0;
    }
    int lSum = 0, rSum = 0;
    for (int i = 0; i < n; i++) {
        lSum += arr[i][i];
        rSum += arr[i][n - 1 - i];
    }
    return abs(lSum - rSum);
}
