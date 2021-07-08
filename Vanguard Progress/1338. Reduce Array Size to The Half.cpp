// Question Link: https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int &n : arr) {
            counts[n]++;
        }
        priority_queue<int> pq;
        for (auto &it : counts) {
            pq.push(it.second);
        }
        int half = arr.size() / 2, count = 0, res = 0;
        for (; !pq.empty() && count < half; pq.pop(), res++) {
            count += pq.top();
        }
        return res;
    }
};