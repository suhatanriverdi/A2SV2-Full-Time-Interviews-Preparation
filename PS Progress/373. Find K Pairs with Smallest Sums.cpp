// Question Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // {pair sum, {num1, num2}}
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pairsPQ;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                pairsPQ.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }   
        }
        vector<vector<int>> kSmallestPairs;
        for (; k > 0 && !pairsPQ.empty(); pairsPQ.pop(), k--) {
            kSmallestPairs.push_back(pairsPQ.top().second);
        }
        return kSmallestPairs;
    }
};
