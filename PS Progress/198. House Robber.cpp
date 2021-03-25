// Question Link: https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int maxAmountOfMoney = 0, size = nums.size();
        vector<int> memo(size, -1);
        for (int i = 0; i < size && i < 2; i++) {
            int money = robberyHelper(i, nums, memo);
            maxAmountOfMoney = max(money, maxAmountOfMoney);
        }
        return maxAmountOfMoney;
    }
    
    int robberyHelper(int pos, vector<int> &A, vector<int> &memo) {
        if (memo[pos] != -1) {
            return memo[pos];
        }
        int result = 0;
        // Try all valid jumps
        for (int jumpAmount = 2; jumpAmount < A.size() && pos + jumpAmount < A.size(); jumpAmount++) {
            result = max(result, robberyHelper(pos + jumpAmount, A, memo));
        }
        return memo[pos] = result + A[pos];
    }
};
