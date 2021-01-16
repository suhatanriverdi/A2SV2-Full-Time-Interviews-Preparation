// Question Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap; // {num, freq}
        for (int num : nums) {
            freqMap[num]++;
        }
        auto comp = [] (vector<int> &a, vector<int> &b) {
            if (a[1] < b[1]) {
                return true;
            }
            if (a[1] == b[1]) {
                return a[0] > b[0];
            }
            return false;
        };
        vector<vector<int>> freqs;
        for (auto it : freqMap) {
            freqs.push_back({it.first, it.second});
        }
        sort(begin(freqs), end(freqs), comp);
        // for (auto f : freqs) {
        //     cout << f[0] << ": " << f[1] << endl;
        // }
        vector<int> result;
        for (vector<int> &freq : freqs) {
            while (freq[1]--) {
                result.push_back(freq[0]);    
            }
        }
        return result;
    }
};
