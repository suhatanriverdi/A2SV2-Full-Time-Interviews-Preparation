// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        if (size < 2) {
            return 0;
        }
        vector<int> buy(size, 0), sell(size, 0);
        buy[0] = -prices[0]; // Buy prices[0]
        for (int i = 1; i < prices.size(); i++) {
            // Either do nothing, or buy
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            // Either do nothing, or sell
            sell[i] = max(sell[i - 1], prices[i] + buy[i - 1] - fee);
        }
        return sell.back();
    }
};