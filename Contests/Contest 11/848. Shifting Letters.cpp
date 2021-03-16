// Question Link: https://leetcode.com/problems/shifting-letters/

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        vector<long long int> sh(begin(shifts), end(shifts));
        for (int i = sh.size() - 2; i >= 0; i--) {
            sh[i] += sh[i + 1];
        }
        // Shift each char ony once
        for (int i = 0; i < sh.size(); i++) {
            // int div = (shifts[i] / 26);
            int rem = (sh[i] % 26);
            while (rem--) {
                if (S[i] == 'z') {
                    S[i] = 'a';
                } else {
                    S[i]++;
                }
            }
        }
        return S;
    }
};
