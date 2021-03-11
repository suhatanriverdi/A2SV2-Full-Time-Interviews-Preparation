// Question Link: https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/

class Solution {
private:
    vector<vector<int>> moves = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 0, 1, -1}, {0, 0, -1, 1}};
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int N = grid.size();
        set<vector<int>> seen;
        queue<vector<int>> todo; // { tx, ty, hx, hy, minSteps } ~==>
        todo.push({0, 0, 0, 1, 0});
        seen.insert({0, 0, 0, 1});
        while (!todo.empty()) {
            vector<int> cur = todo.front(), newCur, move;
            todo.pop();
            if (cur[0] == N - 1 && cur[1] == N - 2 && cur[2] == N - 1 && cur[3] == N - 1) {
                return cur[4];
            }
            for (int ithMove = 0; ithMove < moves.size(); ithMove++) {
                move = moves[ithMove];
                int tX = cur[0] + move[0], tY = cur[1] + move[1];
                int hX = cur[2] + move[2], hY = cur[3] + move[3];
                newCur = { tX, tY, hX, hY };
                char prevDirection = (cur[0] == cur[2] ? 'H' : 'V');
                if (inside(newCur, N, ithMove, prevDirection, grid) && seen.find(newCur) == seen.end()) {
                    todo.push({tX, tY, hX, hY, cur[4] + 1});
                    seen.insert(newCur);
                }
            }
        }
        return -1;
    }
    
    bool inside(vector<int> &cur, int &N, int &move, char &prevDirection, vector<vector<int>> &grid) {
        // Inside check
        if (cur[0] < 0 || cur[0] >= N || cur[2] < 0 || cur[2] >= N ||
           cur[1] < 0 || cur[1] >= N || cur[3] < 0 || cur[3] >= N) {
            return false;
        }
        // Go once cell right, check only head part
        if (move == 0 && (grid[cur[0]][cur[1]] == 1 || grid[cur[2]][cur[3]] == 1)) {
            return false;
        }
        // Go once cell down, check both head and tail
        if (move == 1 && (grid[cur[0]][cur[1]] == 1 || grid[cur[2]][cur[3]] == 1)) {
            return false;
        }
        // Rotate clocwise if Horizontal
        if (move == 2 && (prevDirection == 'V' || grid[cur[2]][cur[3]] == 1 || grid[cur[2]][cur[3] + 1] == 1)) {
            return false;
        }
        // Rotate counter-clocwise if Vertical
        if (move == 3 && (prevDirection == 'H' || grid[cur[2]][cur[3]] == 1 || grid[cur[2] + 1][cur[3]] == 1)) {
            return false;
        }
        return true;
    }
};
