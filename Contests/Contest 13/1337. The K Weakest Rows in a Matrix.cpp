// Question Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& M, int k) {
        vector<pair<int, int>> A;
        for (int i = 0; i < M.size(); i++) {
            for (int j = 1; j < M[i].size(); j++) {
                M[i][j] += M[i][j - 1];
            }
            A.push_back({M[i].back(), i}); // Num of soldiers, row
        }
        auto comp = [](pair<int, int> &a, pair<int, int> &b) {
            if (a.first < b.first) {
                return true;
            } 
            if (a.first == b.first && a.second < b.second) {
                return true;
            }
            return false;
        };
        sort(begin(A), end(A), comp);
        vector<int> result;
        for (int i = 0; i < A.size() && k > 0; i++, k--) {
            result.push_back(A[i].second);
        }
        return result;
    }
};
