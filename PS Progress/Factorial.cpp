// Question Link: https://www.hackerrank.com/challenges/30-recursion/problem

int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}