// Question Link: https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(begin(citations), end(citations), greater<>());
        int hIndex = 1;
        for (; hIndex <= citations.size() && hIndex <= citations[hIndex - 1]; hIndex++) {};
        return hIndex - 1;
    }
};
