// Question Link: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>> numsPQ(begin(A), end(A));
        while (!numsPQ.empty() && K-- > 0) {
            int cur = numsPQ.top();
            numsPQ.pop();
            if (cur >= 0) {
                K %= 2;
            }
            numsPQ.push(-1 * cur);
        }
        int largestSum = 0;
        for (; !numsPQ.empty(); numsPQ.pop()) {
            largestSum += numsPQ.top();
        }
        return largestSum;
    }
};