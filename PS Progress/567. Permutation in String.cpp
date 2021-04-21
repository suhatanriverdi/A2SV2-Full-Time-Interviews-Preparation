// Question Link: https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz1 = s1.size(), sz2 = s2.size();
        if (sz1 > sz2) {
            return false;
        }
        // Count the number of occurences of letters in s1
        vector<int> counts(26, 0), s2Map(26, 0);
        for (int i = 0; i < sz1; i++) {
            counts[s1[i] - 'a']++;
            // Create the fixed window for s2
            s2Map[s2[i] - 'a']++;
        }
        int L = 0, R = sz1;
        while (R <= sz2) {
            if (s2Map == counts) {
                return true;
            }
            if (R == sz2) {
                break;
            }
            s2Map[s2[R] - 'a']++;
            s2Map[s2[L] - 'a']--;
            R++;
            L++;
        }
        return false;
    }
};