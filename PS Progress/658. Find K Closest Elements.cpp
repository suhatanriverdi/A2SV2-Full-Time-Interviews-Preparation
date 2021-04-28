// Question Link: https://leetcode.com/problems/find-k-closest-elements/

// 36ms Two Pointers Solution
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        // Find starting point
        vector<int>::iterator it = lower_bound(begin(arr), end(arr), x);
        if (it == arr.begin()) {
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        else if (it == arr.end()) {
            return vector<int>(arr.begin() + n - k, arr.end());
        }
        // Find starting index
        int center = it - arr.begin(), R = center + 1, L = center - 1;
        vector<int> result, rVal, lVal, rightSortedPart, leftSortedPart; // {val, dif}
        // If x is in array
        if (*it == x) {
            k--;
        } else {
            R--;
        }
        while (k > 0) {
            // Get number from right
            if (R < n) {
                rVal = {arr[R], abs(arr[R] - x)};
            } else {
                rVal = {INT_MAX, INT_MAX};
            }
            // Get number from left
            if (L >= 0) {
                lVal = {arr[L], abs(arr[L] - x)};
            } else {
                lVal = {INT_MAX, INT_MAX};
            }
            if (lVal[1] < rVal[1]) {
                leftSortedPart.push_back(lVal[0]);
                L--;
            }
            else if (lVal[1] == rVal[1]) {
                if (lVal[0] < rVal[0]) {
                    leftSortedPart.push_back(lVal[0]);
                    L--;
                }
                else {
                    rightSortedPart.push_back(rVal[0]);
                    R++;
                }
            }
            else {
                rightSortedPart.push_back(rVal[0]);
                R++;
            }
            k--;
        }
        // Save the results
        for (int i = leftSortedPart.size() - 1; i >= 0; i--) {
            result.push_back(leftSortedPart[i]);
        }
        if (*it == x) {
            result.push_back(x);
        }
        for (int &n : rightSortedPart) {
            result.push_back(n);
        }
        return result;
    }
};

// 168ms Heap Solution
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        auto comp = [](vector<int> &a, vector<int> &b) {
            if (a[0] > b[0]) {
                return true;
            }
            if (a[0] == b[0]) {
                return a[1] > b [1];
            }
            return false;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        // Find starting point
        vector<int>::iterator it = lower_bound(begin(arr), end(arr), x);
        if (it == arr.begin()) {
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        else if (it == arr.end()) {
            return vector<int>(arr.begin() + n - k, arr.end());
        }
        // Go right k times
        for (int i = (it - arr.begin()) + 1, till = k + 1; i < n && till > 0; i++, till--) {
            pq.push({abs(arr[i] - x), arr[i]});
        }
        // Go left k times
        for (int i = (it - arr.begin()), till = k + 1; i >= 0 && till > 0; i--, till--) {
            pq.push({abs(arr[i] - x), arr[i]});
        }
        vector<int> result;
        while (!pq.empty() && k > 0) {
            result.push_back(pq.top()[1]);
            pq.pop();
            k--;
        }
        sort(begin(result), end(result));
        return result;
    }
};
