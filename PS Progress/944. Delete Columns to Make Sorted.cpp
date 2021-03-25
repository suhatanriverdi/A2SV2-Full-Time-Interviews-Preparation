// Question Link: https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string> &S) {
        int result = 0;
        for (int i = 0; i < S[0].size(); i++) {
            for (int j = 1; j < S.size(); j++) {
                if (S[j][i] < S[j - 1][i]) {
                    result++;
                    break;
                }
            }   
        }
        return result;
    }
};
