// Question Link: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int, int> maxMap;
        for (auto &rect : rectangles) {
            maxMap[min(rect[0], rect[1])]++;
        }
        return (--maxMap.end())->second;
    }
};