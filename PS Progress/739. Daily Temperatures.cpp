// Question Link: https://leetcode.com/problems/daily-temperatures/submissions/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        stack<int> s; // Monothone decreasing stack where we keep track of indices
        for (int i = 0; i < T.size(); i++) {
            while (!s.empty() && T[s.top()] < T[i]) {
                result[s.top()] = abs(i - s.top());
                s.pop();
            }
            s.push(i);
        }
        for (; !s.empty(); s.pop()) {
            T[s.top()] = 0;
        }
        return result;
    }
};