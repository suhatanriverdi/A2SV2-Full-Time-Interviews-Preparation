// Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// DP Top-Down Solution | Longest Common Substring/Subarray
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int M = A.size();
        int N = B.size(), result = 0;
        int memo[1001][1001];
        memset(memo, -1, sizeof(memo));
        helper(M, N, result, A, B, memo);
        return result;
    }
    
    int helper(int i, int j, int &res, vector<int> &A, vector<int> &B, int memo[][1001]) {
        if (i == 0 || j == 0) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        helper(i, j - 1, res, A, B, memo);
        helper(i - 1, j, res, A, B, memo);
        
        if (A[i - 1] == B[j - 1]) {
            memo[i][j] = 1 + helper(i - 1, j - 1, res, A, B, memo);
            res = max(res, memo[i][j]);
            return memo[i][j];
        }
        
        return memo[i][j] = 0;
    }
};

// DP Bottom-Up Sollution O(M * N) 388 ms | Longest Common Substring/Subarray
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int M = A.size() + 1;
        int N = B.size() + 1;
        int longestCommonSubArrayLen = 0;
        vector<vector<int>> dp(M, vector<int>(N, 0));
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    longestCommonSubArrayLen = max(longestCommonSubArrayLen, dp[i][j]);
                }
            }   
        }
        return longestCommonSubArrayLen;
    }
};

// Initial SOlution O(N^2) 988 ms
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1Len = nums1.size(), n2Len = nums2.size();
        // Store all starting subarray indices of the numbers
        vector<vector<int>> indices(101);
        for (int i = 0; i < n2Len; i++) {
            indices[nums2[i]].push_back(i);
        }
        
        int res = 0, tmp;
        for (int i = 0; i < n1Len; i++) {
            // If possible next answer is not longer than previously found answer
            if (n1Len - i <= res) {
                break;
            }
            for (int &j : indices[nums1[i]]) {
                tmp = commonSubArrLen(i, j, nums1, nums2, n1Len, n2Len);
                res = max(res, tmp);
            }
        }
        
        return res;
    }
    
    int commonSubArrLen(int i, int j, vector<int>& nums1, vector<int>& nums2, int &n1Len, int &n2Len) {
        int len = 0;
        while (i < n1Len && j < n2Len && nums1[i] == nums2[j]) {
            i++;
            j++;
            len++;
        }
        return len;
    }
};