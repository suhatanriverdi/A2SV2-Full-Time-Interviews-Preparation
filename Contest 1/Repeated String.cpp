// Question Link: https://www.hackerrank.com/contests/a2sv2/challenges/repeated-string

// Complete the repeatedString function below.
long repeatedString(string s, long n) { 
    int numOfAs = 0, strSize = s.size(), left = (n % strSize);
    long long int result = 0;
    for (char c : s) {
        if (c == 'a') {
            numOfAs++;
        }
    }
    result += (n / strSize) * numOfAs;
    for (int i = 0; left && i < strSize; i++, left--) {
        if (s[i] == 'a') {
            result++;
        }
    }
    return result;
}