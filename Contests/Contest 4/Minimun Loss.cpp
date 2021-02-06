// Question Link: hackerrank.com/contests/a2sv-contest-4/challenges/minimum-loss/

// Complete the minimumLoss function below.
int minimumLoss(vector<long> price) {
    unordered_map<int, int> mp; // {number, original index}
    for (int i = 0; i < price.size(); i++) {
        mp[price[i]] = i;
    }
    sort(begin(price), end(price));
    long long res = LONG_LONG_MAX;
    for (int i = 1; i < price.size(); i++) {
        long long diff = (price[i] - price[i - 1]);
        if (diff > 0 && (mp[price[i]] < mp[price[i - 1]]) && diff < res) {
          res = diff;
        }
    }
    return res;
}
