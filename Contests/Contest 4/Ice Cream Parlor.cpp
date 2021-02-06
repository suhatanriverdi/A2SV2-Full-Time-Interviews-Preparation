// Question Link: https://www.hackerrank.com/contests/a2sv-contest-4/challenges/icecream-parlor

// Complete the icecreamParlor function below.
vector<int> icecreamParlor(int m, vector<int> arr) {
    // sort(begin(arr), end(arr), less<int>;
    // cout << arr[0] << endl;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == m) {
                res = {i + 1, j + 1};
                break;
            }
        }   
    }
      return res;
}
