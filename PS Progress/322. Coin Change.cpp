// Question Link: https://leetcode.com/problems/coin-change

// Bottom Up with Sorting
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Each index denotes that the fewest number of coins used to get amount ith
        // e.g dp[3] = 5 -> we have used 5 coins to get amount = 3 and 5 is the fewest num of coins among the others
        vector<int> dp(amount + 1, 10001);
        // Eventually we will have the fewest num of coins to get given amount at the end
        // We have 0 steps to get 0
        dp[0] = 0;
        // Sort to optimize if statement in the loop, we can skip the numbers greater than the amount now
        sort(begin(coins), end(coins));
        for (int i = 1; i < amount + 1; i++) {
            for (int &coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                } else {
                    break;
                }
            }
        }
        return (dp[amount] == 10001 ? -1 : dp[amount]);
    }
};

// Bottom Up without Sort
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Each index denotes that the fewest number of coins used to get amount ith
        // e.g dp[3] = 5 -> we have used 5 coins to get amount = 3 and 5 is the fewest num of coins among the others
        vector<int> dp(amount + 1, 10001);
        // Eventually we will have the fewest num of coins to get given amount at the end
        // We have 0 steps to get 0
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
            for (int &coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return (dp[amount] == 10001 ? -1 : dp[amount]);
    }
};

// Top Down Using Array 52ms
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // unordered_map<int, int> memo;
        int memo[10001];
        memset(memo, -1, sizeof(memo));
        int answer = helper(0, coins, amount, memo);
        return (answer == 10001) ? -1 : answer;
    }
    
    int helper(vector<int> &coins, int amount, int memo[]) {
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

// Top Down Using Map 436ms
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        int answer = helper(0, coins, amount, memo);
        return (answer == 10001) ? -1 : answer;
    }
    
    int helper(vector<int> &coins, int amount, unordered_map<int, int> &memo) {
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
