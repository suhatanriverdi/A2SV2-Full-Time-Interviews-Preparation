// Question Link: https://www.hackerrank.com/challenges/mark-and-toys/problem

int maximumToys(vector<int> prices, int k) {
    sort(begin(prices), end(prices));
    int result = 0; 
    for (int i = 0; i < prices.size() && k > 0; i++) {
        if (prices[i] < k) {
            k -= prices[i];
           result++; 
        }
    }
    return result;
}