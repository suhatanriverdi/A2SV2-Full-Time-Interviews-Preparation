// Question Link: https://www.hackerrank.com/challenges/3d-surface-area/problem

int surfaceArea(vector<vector<int>> A) {
    int result = 0, rightLeftMaxSum = 0, topBottomMaxSum = 0, tmpMax; // Total surface area
    int M = A.size();
    int N = A[0].size();
    // We have 6 surfaces, top bottom left right forward backward
    // Top and Bottom will have the same surface area
    result += (M * N) * 2;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // Find Right and Left surface areas
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (vector<int> dir : directions) {
                int nx = i + dir[0]; 
                int ny = j + dir[1];
                // Corners or Borders
                if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
                    result += A[i][j];
                }
                else if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                    result += (A[i][j] > A[nx][ny] ? (A[i][j] - A[nx][ny]) : 0);
                }
            }
        }
    }
    return result;
}
