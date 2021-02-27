// Question Link: https://www.hackerrank.com/contests/a2sv-contest-7/challenges/pairs

int pairs(int k, vector<int> arr) {
    sort(begin(arr), end(arr));
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            int diff = arr[j] - arr[i];
            if (diff > k) {
                break; 
            }
            if (diff == k) {
                cnt++; 
            }
        }
    }
    return cnt;
}