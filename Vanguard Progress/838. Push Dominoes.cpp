// Question https://leetcode.com/problems/push-dominoes

class Solution {
public:
    string pushDominoes(string dominoes) {
        int N = dominoes.size();
        queue<int> todo;
        vector<int> fallLevel(N, -1);
        // Get currently falling dominoes
        for (int i = 0; i < N; i++) {
            if (dominoes[i] != '.') {
                todo.push(i); // { index, fall level }
                fallLevel[i] = 0; // { fall level }
            }
        }
        
        while (!todo.empty()) {
            int curIndex = todo.front();
            todo.pop();
            if (dominoes[curIndex] == 'L') {
                if (isStatic(curIndex - 1, N, dominoes)) {
                    todo.push( curIndex - 1 );
                    dominoes[curIndex - 1] = 'L';
                    fallLevel[curIndex - 1] = fallLevel[curIndex] + 1;
                }
            }
            else if (dominoes[curIndex] == 'R') {
                if (isStatic(curIndex + 1, N, dominoes)) {
                    todo.push( curIndex + 1 );
                    dominoes[curIndex + 1] = 'R';
                    fallLevel[curIndex + 1] = fallLevel[curIndex] + 1;
                }
            }
        }
        
        // Last pass for middle dominoes
        for (int i = 1; i < N - 1; i++) {
            if (fallLevel[i - 1] == fallLevel[i + 1] && fallLevel[i] != 0 && dominoes[i - 1] != dominoes[i + 1]) {
                dominoes[i] = '.';
            }
        }
        
        return dominoes;
    }
    
    bool isStatic(int index, int &N, string &dominoes) {
        if (index < 0 || index >= N || dominoes[index] != '.') {
            return false;
        }
        return true;
    }
};