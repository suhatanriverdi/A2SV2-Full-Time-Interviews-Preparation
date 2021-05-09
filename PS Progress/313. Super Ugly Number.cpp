// Question Link: https://leetcode.com/problems/super-ugly-number/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long>> minheap;
        minheap.push(1);
        unordered_set<long> seen = {1};
        while (n > 1) {
            long cur = minheap.top();
            minheap.pop();
            n--;
            for (int &prime : primes) {
                long fact = prime * cur;
                if (seen.find(fact) == seen.end()) {
                    minheap.push(fact);
                    seen.insert(fact);
                }
            }
        }
        return minheap.top();
    }
};