// Question Link: https://leetcode.com/problems/finding-the-users-active-minutes/

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> uaMap;
        // Find UAM for each user
        for (vector<int> &log : logs) {
            uaMap[log[0]].insert(log[1]);
        }
        vector<int> result(k, 0);
        for (auto &p : uaMap) {
            result[p.second.size() - 1]++;
        }
        return result;
    }
};