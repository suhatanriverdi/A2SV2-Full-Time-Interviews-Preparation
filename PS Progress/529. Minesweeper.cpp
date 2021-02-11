// Question Link: https://leetcode.com/problems/minesweeper

// DFS Solution
class Solution {
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // If mine is at the click position, gave is over
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        } 
        // Run bfs
        dfs(board, click[0], click[1]);
        return board;
    }
    
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'E') {
            return;
        }
        checkCellsAround(board, x, y);
        if (isdigit(board[x][y])) {
            return;
        }
        for (vector<int> &dir : dirs) {
            int nx = dir[0] + x;
            int ny = dir[1] + y;
            dfs(board, nx, ny);
        }
    }
    
    // Turns a cell into either digit or blank cell by looking around itself
    void checkCellsAround(vector<vector<char>> &board, int x, int y) {
        int minesAroundCount = 0;
        for (vector<int> &dir : dirs) {
            int nx = dir[0] + x;
            int ny = dir[1] + y;
            // Check if we are inside of the array and there are mines around us, if so count them
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'M') {
                minesAroundCount++;
            }
        }
        // If there is at least one mine, we have to turn our cell into digit cell
        if (minesAroundCount > 0) {
            board[x][y] = '0' + minesAroundCount;
        }
        // Else we can turn our cell into blank cell
        else {
            board[x][y] = 'B';
        }
    }
};

// BFS Solution
class Solution {
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // If mine is at the click position, gave is over
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        } 
        // If there is any M around us, we only need to turn our cell into digit
        checkCellsAround(board, click);
        if (isdigit(board[click[0]][click[1]])) {
            return board;
        }
        // Otherwise, run bfs to expand
        else {
            bfs(board, click);
        }
        return board;
    }
    
    void bfs(vector<vector<char>> &board, vector<int> &click) {
        // // First process ourself
        // checkCellsAround(board, click);
        queue<vector<int>> todo;
        todo.push(click);
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            // Process our neighbours
            for (vector<int> &dir : dirs) {
                int nx = dir[0] + cur[0];
                int ny = dir[1] + cur[1];
                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'E') {
                    vector<int> cell = {nx, ny};
                    checkCellsAround(board, cell);
                    // After process around us, check if our recently processed cell is Blank, if so push into queue
                    if (board[nx][ny] == 'B') {
                        todo.push(cell);
                    }
                }
            }
        }
    }
    
    // Turns a cell into either digit or blank cell by looking around itself
    void checkCellsAround(vector<vector<char>> &board, vector<int> &cell) {
        int minesAroundCount = 0;
        for (vector<int> &dir : dirs) {
            int nx = dir[0] + cell[0];
            int ny = dir[1] + cell[1];
            // Check if we are inside of the array and there are mines around us, if so count them
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'M') {
                minesAroundCount++;
            }
        }
        // If there is at least one mine, we have to turn our cell into digit cell
        if (minesAroundCount > 0) {
            board[cell[0]][cell[1]] = '0' + minesAroundCount;
        }
        // Else we can turn our cell into blank cell
        else {
            board[cell[0]][cell[1]] = 'B';
        }
    }
};
