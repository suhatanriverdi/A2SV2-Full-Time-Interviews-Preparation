// Question Link: https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0) {
            return result;
        }
        unordered_set<int> uniqueNumsSet, added;
        for (int n1 : nums1) {
            uniqueNumsSet.insert(n1);
        }
        for (int n2 : nums2) {
            if (uniqueNumsSet.find(n2) != uniqueNumsSet.end() && added.find(n2) == added.end()) {
                result.push_back(n2);
                added.insert(n2);
            }
        }
        return result;
    }
};