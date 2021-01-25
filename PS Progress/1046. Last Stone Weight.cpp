// Question Link: https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> PQ(begin(stones), end(stones));
        while (PQ.size() > 1) {
            int A = PQ.top();
            PQ.pop();
            int B = PQ.top();
            PQ.pop();
            int smashSum = A - B;
            if (smashSum != 0) {
                PQ.push(smashSum);
            }
        }
        return (PQ.empty() ? 0 : PQ.top());
    }
};