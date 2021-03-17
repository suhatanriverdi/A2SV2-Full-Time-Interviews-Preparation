// Question Link: https://leetcode.com/problems/word-search-ii/

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int M = board.size();
        int N = board[0].size();
        vector<vector<vector<int>>> letterBegins(26); // {letter, {starting coordinates}}
        // Saves the x, y coordinates where the letters start from
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                letterBegins[board[i][j] - 'a'].push_back({i, j});
            }   
        }
        // Start searching the words by DFS
        vector<string> result;
        for (string &word : words) {
            // Start from the same letters only
            char lastLetter = word.back();
            for (vector<int> &beginPoint : letterBegins[lastLetter - 'a']) {
                bool found = false;
                hasWord(beginPoint[0], beginPoint[1], word, board, found);
                if (found == true) {
                    result.push_back(word);
                    break; // Skip to next word
                }
            }
        }
        return result;
    }
    
    // Searches if Board has the word starting from last letter
    void hasWord(int x, int y, string word, vector<vector<char>> &board, bool &found) {
        if (word.empty()) {
            found = true;
            return;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '*' || word.back() != board[x][y]) {
            return;
        }
        char prevLetter = board[x][y];
        word.pop_back();
        board[x][y] = '*';
        hasWord(x + 1, y, word, board, found);
        hasWord(x - 1, y, word, board, found);
        hasWord(x, y + 1, word, board, found);
        hasWord(x, y - 1, word, board, found);
        // Backtracking
        board[x][y] = prevLetter;
    }
};
