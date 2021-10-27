// Question Link: https://leetcode.com/problems/min-cost-climbing-stairs/

// Bottom-Up Solution O(N) Time & O(1) Space
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0); // result min cost
        for (int i = 2; i < cost.size(); i++) {
            cost[i] = min(cost[i - 1] + cost[i], cost[i - 2] + cost[i]);
        }
        return cost.back();
    }
};

// Top-Down Solution O(N) Time & O(2N) Space(Callstack + memo)
class Solution {
public:
    int minCostHelper(int index, vector<int> &cost, int memo[]) {
        if (memo[index] != -1) {
            return memo[index];
        }
        if (index == 0 || index == 1) {
            return cost[index];
        }
        int A = minCostHelper(index - 1, cost, memo);
        int B = minCostHelper(index - 2, cost, memo);
        memo[index] = min(A, B) + cost[index];
        return memo[index];
    }
    
    int minCostClimbingStairs(vector<int> &cost) {
        cost.push_back(0);
        int memo[1001];
        memset(memo, -1, sizeof(memo));
        return minCostHelper(cost.size() - 1, cost, memo);
    }
};