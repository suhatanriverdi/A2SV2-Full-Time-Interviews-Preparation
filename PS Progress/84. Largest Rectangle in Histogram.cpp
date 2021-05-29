// Question Link: https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // Find the first left smaller element for current height
        vector<int> leftIndices(n, -1);
        stack<int> leftSmallerStack;
        leftSmallerStack.push(0);
        for (int i = 1; i < heights.size(); i++) {
            while (!leftSmallerStack.empty() && heights[leftSmallerStack.top()] >= heights[i]) {
                leftSmallerStack.pop();
            }
            leftIndices[i] = leftSmallerStack.empty() ? -1 : leftSmallerStack.top();
            leftSmallerStack.push(i);
        }
        
        // Find the first right smaller element for current height
        vector<int> rightIndices(n, n);
        stack<int> rightSmallerStack;
        rightSmallerStack.push(heights.size() - 1);
        for (int i = heights.size() - 2; i >= 0; i--) {
            while (!rightSmallerStack.empty() && heights[rightSmallerStack.top()] >= heights[i]) {
                rightSmallerStack.pop();
            }
            rightIndices[i] = rightSmallerStack.empty() ? n : rightSmallerStack.top();
            rightSmallerStack.push(i);
        }
        
        // Calculate maximum area
        int maxArea = heights[0];
        for (int i = 0; i < n; i++) {
            int curArea = heights[i] * (rightIndices[i] - leftIndices[i] - 1);
            maxArea = max(maxArea, curArea);
        }
        return maxArea;
    }
};