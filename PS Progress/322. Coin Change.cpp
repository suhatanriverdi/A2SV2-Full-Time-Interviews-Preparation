// Question Link: https://leetcode.com/problems/coin-change

// Using Array 52ms
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // unordered_map<int, int> memo;
        int memo[10001];
        memset(memo, -1, sizeof(memo));
        int answer = helper(0, coins, amount, memo);
        return (answer == 10001) ? -1 : answer;
    }
    
    int helper(int cur, vector<int> &coins, int amount, int memo[]) {
        if (memo[amount] != -1) {
            return memo[amount];
        }
        // One of the possible anwers found
        if (amount == 0) {
            return 0;
        }
        int answer = 10001;
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                answer = min(answer, helper(i, coins, amount - coins[i], memo));
            }
        }
        // if answer is 10001 don't change it. Just return the result as is. Otherwise add 1 to the result.
        answer = ((answer != 10001) ? (answer + 1) : (answer));
        memo[amount] = answer;
        return answer;
    }
};

// Using Map 436ms
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        int answer = helper(0, coins, amount, memo);
        return (answer == 10001) ? -1 : answer;
    }
    
    int helper(int cur, vector<int> &coins, int amount, unordered_map<int, int> &memo) {
        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }
        // One of the possible anwers found
        if (amount == 0) {
            return 0;
        }
        int answer = 10001;
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                answer = min(answer, helper(i, coins, amount - coins[i], memo));
            }
        }
        // if answer is 10001 don't change it. Just return the result as is. Otherwise add 1 to the result.
        answer = ((answer != 10001) ? (answer + 1) : (answer));
        memo[amount] = answer;
        return answer;
    }
};