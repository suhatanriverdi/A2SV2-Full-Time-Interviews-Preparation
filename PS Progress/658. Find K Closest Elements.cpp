// Question Link: https://leetcode.com/problems/find-k-closest-elements/

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