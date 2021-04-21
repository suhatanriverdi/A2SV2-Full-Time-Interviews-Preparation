// Question Link: https://leetcode.com/problems/permutation-in-string/

// Way Better O(N) Solution
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

// First Approach
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size(), s2Size = s2.size();
        if (s1Size > s2.size()) {
            return false;
        }
        unordered_map<char, int> counts;
        for (char c : s1) {
            counts[c]++;
        }
        for (int i = 0; i < s2Size; i++) {
            // Possible substring match
            if (counts.find(s2[i]) != counts.end()) {
                // Check valid substring
                bool found = true;
                unordered_map<char, int> substrMap;
                for (int k = s1Size, s2Idx = i; k > 0; k--, s2Idx++) {
                    if (counts.find(s2[s2Idx]) == counts.end()) {
                        i = s2Idx;
                        found = false;
                        break;
                    }
                    substrMap[s2[s2Idx]]++;
                }
                // Check if valid substring found
                if (found && counts == substrMap) {
                    return true;
                }
            }
        }
        return false;
    }
};
