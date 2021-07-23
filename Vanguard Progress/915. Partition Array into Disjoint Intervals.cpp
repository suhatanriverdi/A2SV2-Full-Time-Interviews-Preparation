// Question https://leetcode.com/problems/partition-array-into-disjoint-intervals/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int N = nums.size();
        vector<int> smallestOnRight(N, 0);
        int curSmallest = INT_MAX;
        // Find smallest value on the right
        for (int i = N - 1; i >= 0; i--) {
            smallestOnRight[i] = curSmallest;
            // Update smallest
            curSmallest = min(curSmallest, nums[i]);
        }
        // Find the partitioning point
        int curBiggest = nums[0];
        for (int i = 0; i < N; i++) {
            if (curBiggest <= smallestOnRight[i]) {
                return i + 1;   
            }
            curBiggest = max(curBiggest, nums[i]);
        }
        return N;
    }
};