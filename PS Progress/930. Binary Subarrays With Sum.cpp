// Question Link: https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size(), result = 0;
        if (n == 0) {
            return 0;
        }
        // Zip zeros, to know how many zeros are there on my left and right
        // {{0, 3}... zero and its count
        vector<vector<int>> zipA = { {A[0], 1} };
        // Indices of ones
        vector<int> onesIndices;
        if (A[0] == 1) {
            onesIndices.push_back(0);
        }
        for (int i = 1, zipIndex = 1; i < n; i++) {
            if (A[i] == 0) {
                if (zipA.back()[0] == 0) {
                    zipA.back()[1]++;
                }
                else {
                    zipA.push_back({0, 1});
                    zipIndex++;
                }
            }
            else {
                zipA.push_back({1, 1});
                onesIndices.push_back(zipIndex);
                zipIndex++;
            }
        }
        // If S is 0 case
        if (S == 0) {
            for (vector<int> &tuple : zipA) {
                if (tuple[0] == 0) {
                    result += (tuple[1] * (tuple[1] + 1)) / 2;
                }
            }
            return result;
        }
        // Sliding window
        int LIdx = 0, RIdx = S - 1;
        while (RIdx < onesIndices.size()) {
            int L = onesIndices[LIdx];
            int R = onesIndices[RIdx];
            // Calculate number of subarrays
            int leftZeros = (((L - 1) >= 0) && (zipA[L - 1][0] == 0)) ? zipA[L - 1][1] : 0;
            int rightZeros = (((R + 1) < zipA.size()) && (zipA[R + 1][0] == 0)) ? zipA[R + 1][1] : 0;
            result += 1 + leftZeros + rightZeros + (rightZeros * leftZeros);
            // Update two pointers
            LIdx++;
            RIdx++;
        }
        return result;
    }
};