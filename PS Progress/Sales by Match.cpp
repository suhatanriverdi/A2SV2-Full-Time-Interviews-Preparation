// Question Link: https://www.hackerrank.com/challenges/sock-merchant/problem

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> sockFrequency;
    for (int a : ar) {
        sockFrequency[a]++;
    }
    int result = 0;
    for (auto s : sockFrequency) {
        result += s.second / 2;
    }
    return result;
}