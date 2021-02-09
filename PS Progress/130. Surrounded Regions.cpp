// Question Link: https://leetcode.com/problems/surrounded-regions

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
