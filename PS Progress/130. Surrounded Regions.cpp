// Question Link: https://leetcode.com/problems/surrounded-regions

// 40ms Initial Solution
// First we thought that we can run dfs from the border O's and keep track of all the O's that are connected each other. We can use set to mark them as visited.

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) {
            return;
        }
        int col = board[0].size();
        set<vector<int>> seen;
        // Check borders if there is any 'O', run DFS for them
        // Check first and last row
        for (int firstRow = 0, lastRow = 0; firstRow < col; firstRow++, lastRow++) {
            if (board[0][firstRow] == 'O') {
                dfs(board, 0, firstRow, seen);
            }
            if (board[row - 1][lastRow] == 'O') {
                dfs(board, row - 1, lastRow, seen);
            }
        }
        // Check first and last column
        for (int firstCol = 0, lastCol = 0; firstCol < row; firstCol++, lastCol++) {
            if (board[firstCol][0] == 'O') {
                dfs(board, firstCol, 0, seen);
            }
            if (board[lastCol][col - 1] == 'O') {
                dfs(board, lastCol, col - 1, seen);
            }
        }
        // After covering all the 'O's on borders, other 'O's have to be surrounded
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If we find any 'O' that is not connected to previously found 'O's, surround it
                if (board[i][j] == 'O' && seen.find({i, j}) == seen.end()) {
                    board[i][j] = 'X';
                }
            }   
        }
    }
    
    void dfs(vector<vector<char>> &board, int x, int y, set<vector<int>> &seen) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == 'X' || seen.find({x, y}) != seen.end()) {
            return;          
        }
        // Keep track of any 'O' found during DFS meaning connected to borders
        seen.insert({x, y});
        dfs(board, x + 1, y, seen);
        dfs(board, x - 1, y, seen);
        dfs(board, x, y + 1, seen);
        dfs(board, x, y - 1, seen);
    }
};


// Better Solution 12ms
// Since we can know the size of the board, we can create and use 2D array instead of using sorted set

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) {
            return;
        }
        int col = board[0].size();
        vector<vector<bool>> seen(row, vector<bool>(col, false));
        // Check borders if there is any 'O', run DFS for them
        // Check first and last row
        for (int firstRow = 0, lastRow = 0; firstRow < col; firstRow++, lastRow++) {
            if (board[0][firstRow] == 'O') {
                dfs(board, 0, firstRow, seen);
            }
            if (board[row - 1][lastRow] == 'O') {
                dfs(board, row - 1, lastRow, seen);
            }
        }
        // Check first and last column
        for (int firstCol = 0, lastCol = 0; firstCol < row; firstCol++, lastCol++) {
            if (board[firstCol][0] == 'O') {
                dfs(board, firstCol, 0, seen);
            }
            if (board[lastCol][col - 1] == 'O') {
                dfs(board, lastCol, col - 1, seen);
            }
        }
        // After covering all the 'O's on borders, other 'O's have to be surrounded
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If we find any 'O' that is not connected to previously found 'O's, surround it
                if (board[i][j] == 'O' && seen[i][j] == false) {
                    board[i][j] = 'X';
                }
            }   
        }
    }
    
    void dfs(vector<vector<char>> &board, int x, int y, vector<vector<bool>> &seen) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == 'X' || seen[x][y]) {
            return;          
        }
        // Keep track of any 'O' found during DFS meaning connected to borders
        seen[x][y] = true;
        dfs(board, x + 1, y, seen);
        dfs(board, x - 1, y, seen);
        dfs(board, x, y + 1, seen);
        dfs(board, x, y - 1, seen);
    }
};

// Better Memory Optimized Solution
// We can even remove "seen" visited array which turns our space complexity into constant memory usage, we don't need that, we can use the grid as is to mark O's, two birds one stone! (I used M's to mark connected O's on the borders because M is my name's first letter :)

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) {
            return;
        }
        int col = board[0].size();
        // Check borders if there is any 'O', run DFS for them
        // Check first and last row
        for (int firstRow = 0, lastRow = 0; firstRow < col; firstRow++, lastRow++) {
            if (board[0][firstRow] == 'O') {
                dfs(board, 0, firstRow);
            }
            if (board[row - 1][lastRow] == 'O') {
                dfs(board, row - 1, lastRow);
            }
        }
        // Check first and last column
        for (int firstCol = 0, lastCol = 0; firstCol < row; firstCol++, lastCol++) {
            if (board[firstCol][0] == 'O') {
                dfs(board, firstCol, 0);
            }
            if (board[lastCol][col - 1] == 'O') {
                dfs(board, lastCol, col - 1);
            }
        }
        // After covering all the 'O's on borders, other 'O's have to be surrounded
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If we find any 'O' that is not connected to previously found 'O's, surround it
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } 
            }   
        }
        // Revert back the O's that are connected to borders to X's
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'M') {
                    board[i][j] = 'O';
                }
            }   
        }
    }
    
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O') {
            return;          
        }
        // Keep track of any 'O' found during DFS meaning connected to borders
        board[x][y] = 'M';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
};

// Even Better Solution Without Using Two Loops At The End
// We can do the marking within the one loop!

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) {
            return;
        }
        int col = board[0].size();
        // Check borders if there is any 'O', run DFS for them
        // Check first and last row
        for (int firstRow = 0, lastRow = 0; firstRow < col; firstRow++, lastRow++) {
            if (board[0][firstRow] == 'O') {
                dfs(board, 0, firstRow);
            }
            if (board[row - 1][lastRow] == 'O') {
                dfs(board, row - 1, lastRow);
            }
        }
        // Check first and last column
        for (int firstCol = 0, lastCol = 0; firstCol < row; firstCol++, lastCol++) {
            if (board[firstCol][0] == 'O') {
                dfs(board, firstCol, 0);
            }
            if (board[lastCol][col - 1] == 'O') {
                dfs(board, lastCol, col - 1);
            }
        }
        // After covering all the 'O's on borders, other 'O's have to be surrounded
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If we find any 'O' that is not connected to previously found 'O's, surround it
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } 
                // Revert back the O's that are connected to borders to X's
                else if (board[i][j] == 'M') {
                    board[i][j] = 'O';
                }
            }   
        }
    }
    
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O') {
            return;          
        }
        // Keep track of any 'O' found during DFS meaning connected to borders
        board[x][y] = 'M';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
};
