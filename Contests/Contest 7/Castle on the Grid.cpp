// Question Link: https://www.hackerrank.com/contests/a2sv-contest-7/challenges/castle-on-the-grid

bool inside(int nx, int ny, int &N) {
    if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
        return false;
    }
    return true;
}

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int M = grid.size();
    int N = grid[0].size();
    if (grid[startX][startY] == 'X') {
        return 0;
    }
    // Dists
    vector<vector<int>> dists = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> minMove(M + 1, vector<int>(N + 1, 0));
    queue<vector<int>> todo; // {x, y, dist}
    todo.push({startX, startY});
    minMove[startX][startY] = 1;
    while (!todo.empty()) {
        vector<int> cur = todo.front();
        todo.pop();
        for (vector<int> &dist : dists) {
            for (int range = 1; range < N; range++) {                
                int nx = (dist[0] * range) + cur[0];
                int ny = (dist[1] * range) + cur[1];
                // Skip next direction
                if ((inside(nx, ny, N) && grid[nx][ny] == 'X') || inside(nx, ny, N) == false) {
                    break;
                }
                // Keep going that direction till the edge or X
                if (minMove[nx][ny] == 0) {
                    if (nx == goalX && ny == goalY) {
                        return minMove[cur[0]][cur[1]];
                    }
                    todo.push({nx, ny});
                    minMove[nx][ny] = minMove[cur[0]][cur[1]] + 1;
                    nx = dist[0] + nx;
                    ny = dist[1] + ny;
                }
            }
        }
    }
    return 0;
}