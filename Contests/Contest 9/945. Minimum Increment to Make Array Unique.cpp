// Question Link: https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() <= 1) {
            return 0;
        }
        vector<bool> taken(80001, false);
        vector<int> beIncremented;
        for (int &n : A) {
            if (taken[n] == false) {
                taken[n] = true;
            }
            else {
                beIncremented.push_back(n);
            }
        }
        if (beIncremented.size() == 0) {
            return 0;
        }
        sort(begin(beIncremented), end(beIncremented));
        int minCost = 0, incSize = beIncremented.size();
        int t = beIncremented[0] + 1;
        int cur = 0;
        while (cur < beIncremented.size()) {
            if (taken[t] == false && t > beIncremented[cur]) {
                minCost += t - beIncremented[cur];
                cur++;
            }
            t++;
        }
        return minCost;
    }
};
