// Question Link: https://www.hackerrank.com/challenges/cavity-map/problem

bool cavity(vector<string> &grid, int i, int j) {
    if (grid[i][j] > grid[i + 1][j] && grid[i][j] > grid[i - 1][j] &&
       grid[i][j] > grid[i][j + 1] && grid[i][j] > grid[i][j - 1]) {
        return true;
    }
    return false;
}

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {
    if (grid.size() < 3) {
        return grid;
    }
    vector<vector<int>> cavs;
    int n = grid.size();
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (cavity(grid, i, j)) {
                cavs.push_back({i, j});
            }
        }
    }
    for (vector<int> &c : cavs) {
        grid[c[0]][c[1]] = 'X';
    }
    return grid;
}