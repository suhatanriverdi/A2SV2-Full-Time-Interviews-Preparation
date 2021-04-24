// Question Link: https://www.hackerrank.com/challenges/pairs/problem

// In-Contest O(N log N) Solution
int pairs(int k, vector<int> arr) {
    unordered_set<long long int> set(begin(arr), end(arr));
    sort(begin(arr), end(arr), greater<int>());
    long long int tmp, cnt = 0;
    for (int i = 0; i < arr.size() && (arr[i] - k > 0); i++) {
        tmp = arr[i] - k;
        if (set.find(tmp) != set.end()) {
            cnt++;
        }
    }
    return cnt;
}

// After Contest O(N) Solution
int pairs(int k, vector<int> arr) {
    unordered_set<int> set(begin(arr), end(arr));
    int cnt = 0;
    for (auto &n : set) {
        if (set.find(k + n) != set.end()) {
            cnt++;
        }
    }
    return cnt;
}