// Question Link: https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string order, string s) {
        int sCount[27] = { 0 };
        for (char c : s) {
            sCount[c - 'a']++;
        }
        string permuted = "";
        inserter(order, permuted, sCount);
        inserter(s, permuted, sCount);
        return permuted;
    }
    
    void inserter(string &str, string &permuted, int sCount[]) {
        int amount;
        for (char c : str) {
            amount = sCount[c - 'a'];
            if (amount > 0) {
                permuted.insert(end(permuted), amount, c);
                sCount[c - 'a'] = 0;
            }
        }
    }
};
