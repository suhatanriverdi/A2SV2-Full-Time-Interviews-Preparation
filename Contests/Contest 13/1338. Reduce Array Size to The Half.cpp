// Question Link: https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int &n : arr) {
            mp[n]++;
        }
        int half = arr.size() / 2;
        vector<int> counts;
        for (auto it : mp) {
            counts.push_back(it.second);
        }
        if (counts.size() == 1) {
            return 1;
        }
        sort(begin(counts), end(counts));
        int result = 0;
        long long int sum = 0;
        for (int i = counts.size() - 1; i >= 0; i--) {
            if (sum < half) {
                sum += counts[i];
                result++;
            }
        }
        return result;
     }
};


