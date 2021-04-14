// Question Link: https://leetcode.com/problems/subrectangle-queries/

class SubrectangleQueries {
    vector<vector<int>> R;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        R = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; i++) {
            for (int j = col1; j <= col2; j++) {
                R[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return R[row][col];
    }
};