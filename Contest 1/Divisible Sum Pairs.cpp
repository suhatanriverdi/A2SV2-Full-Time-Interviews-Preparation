// Question Link: https://www.hackerrank.com/contests/a2sv2/challenges/divisible-sum-pairs

// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ar[i] + ar[j]) % k == 0) {
                result++;
            }
        }
    }
    return result;
}