// Question Link: https://www.hackerrank.com/challenges/recursive-digit-sum

long long int helper(string &n, long long int result) {
    if (n.size() == 0) {
        return result;
    }
    result += (n.back() - '0');
    n.pop_back();
    return helper(n, result);
}

// Complete the superDigit function below.
int superDigit(string n, int k) {
    long long int result = 0;
    for (char c : n) {
        result += (c - '0');
    }
    result *= k;
    n = to_string(result); 
    while (result >= 10) {
        result = helper(n, 0);
        n = to_string(result);
    }
    return result;
}