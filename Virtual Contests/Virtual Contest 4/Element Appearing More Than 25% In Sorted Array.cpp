// Question Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }
        int ans = 0, occ = 0;
        for (auto it : map) {
            if (it.second > occ) {
                ans = it.first;
                occ = it.second;
            }
        }
        return ans;
    }
};