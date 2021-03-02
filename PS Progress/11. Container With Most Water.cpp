// Question Link: https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& H) {
        int size = H.size(), L = 0, R = size - 1, maxArea = 0, curArea;
        while (L < R) {
            // Calculate current area
            curArea = (R - L) * min(H[L], H[R]);
            // Get the max area seen so far
            maxArea = max(maxArea, curArea);
            // Update two pointers, increase the smaller value side to get higher volume
            if (H[L] < H[R]) {
                L++;
            } else {
                R--;
            }
        }
        return maxArea;
    }
};