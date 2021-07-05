// Question Link: https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int M = mat.size();
        int N = mat[0].size();
        
        // Not possible
        if (M * N != r * c) {
            return mat;
        }
        
        deque<int> elements = getElements(M, N, mat);
        
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = elements.front();
                elements.pop_front();
            }   
        }
        
        return res;
    }
    
    deque<int> getElements(int &M, int &N, vector<vector<int>> &mat) {
        deque<int> elements;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                elements.push_back(mat[i][j]);
            }   
        }
        return elements;
    }
};