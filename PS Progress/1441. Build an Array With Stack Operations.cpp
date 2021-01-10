// Question Link: https://leetcode.com/problems/build-an-array-with-stack-operations/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int i = 1;
        vector<int> fullArr(n, 0);
        for (int &n : fullArr) { n = i++; };
        unordered_set<int> hasNumSet(begin(target), end(target));
        for (int n : fullArr) {
            result.push_back("Push");
            if (n == target.back()) {
                break;
            }
            if (hasNumSet.find(n) == hasNumSet.end()) {
                result.push_back("Pop");
            }
        }
        return result;
    }
};
