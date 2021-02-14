// Question Link: https://www.hackerrank.com/contests/a2sv-contest-5/challenges/sherlock-and-array/

// Complete the balancedSums function below.
string balancedSums(vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        arr[i] += arr[i - 1];
    }
    int totalSum = arr.back();
    for (int i = 0; i < arr.size(); i++) {
        // Left Sum == Right Sum
        if ((totalSum - arr[i]) == ((i - 1) >= 0 ? arr[i - 1] : 0)) {
            return "YES";
        }
    }
    return "NO";
}