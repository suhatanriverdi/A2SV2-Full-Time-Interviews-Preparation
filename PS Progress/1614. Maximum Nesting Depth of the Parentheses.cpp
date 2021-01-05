// Question Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, result = 0;
        for (char c : s) {
            if (c == '(') {
                depth++;
            } 
            else if (c == ')') {
                depth--;
            }
            result = max(depth, result);
        }
        return result;
    }
};