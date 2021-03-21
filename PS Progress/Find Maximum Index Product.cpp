// Question Link: https://www.hackerrank.com/challenges/find-maximum-index-product/problem

long long int solve(vector<int> arr) {
    int n = arr.size();
    stack<int> leftStack, rightStack;
    vector<long long int> L(n, 0);
    // Left
    for (int i = 0; i < n; i++) {
        while (!leftStack.empty() && arr[leftStack.top()] <= arr[i]) {
            leftStack.pop();
        }
        L[i] = (leftStack.empty() ? 0 : leftStack.top() + 1);
        leftStack.push(i);
    }
    // Right
    long long int result = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (!rightStack.empty() && arr[rightStack.top()] <= arr[i]) {
            rightStack.pop();
        }
        L[i] *= (rightStack.empty() ? 0 : rightStack.top() + 1);
        result = max(result, L[i]);
        rightStack.push(i);
    }
    return result;
}
