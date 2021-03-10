// Question Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> tmp;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (!tmp.empty() && s[i] == tmp.back().first) {
                tmp.back().second++;
                if (tmp.back().second == k) {
                    tmp.pop_back();
                }
            }
            else {
                tmp.push_back({s[i], 1});
            }
        }
        string result;
        for (int i = tmp.size() - 1; i >= 0; i--) {
            result += string(tmp[i].second, tmp[i].first);
        }
        return result;
    }
};
