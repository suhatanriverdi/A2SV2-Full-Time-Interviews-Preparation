// Question Link: https://www.hackerrank.com/challenges/crush/problem

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long long int> result(n + 1, 0);
    for (vector<int> &query : queries) {
        result[query[0] - 1] += query[2]; // Put flag
        result[query[1]] -= query[2]; // Remove flag
    }
    long long int maxValue = result[0];
    for (int i = 1; i < result.size(); i++) {
        result[i] += result[i - 1];
        maxValue = max(maxValue, result[i]);
    }
    return maxValue;
}
