// Question Link: https://leetcode.com/problems/longest-palindromic-subsequence/

// Top-Down DP with memoization
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int memo[1001][1001];
        memset(memo, -1, sizeof memo);
        return helper(0, s.size(), s, memo);
    }
    
    // Finds and returns longest palindromic subsequence length
    int helper(int l, int r, string &s, int memo[][1001]) {
        if (memo[l][r] != -1) {
            return memo[l][r];
        }
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return s[l] == s[r];
        }
        if (s[l] == s[r]) {
            memo[l][r] = 2 + helper(l + 1, r - 1, s, memo);
            return memo[l][r];
        }
        else {
            memo[l][r] = max(helper(l, r - 1, s, memo), helper(l + 1, r, s, memo));
            return memo[l][r];
        }
    }
};

// Brute Force Solution Got TLE
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string sub = "";
        return allSubsequences(0, s, sub);
    }
    
    // Finds and returns longest palindromic subsequence length
    int allSubsequences(int i, string &s, string sub) {
        int result = 0;
        if (i == s.size()) {
            if (sub != "") {
                if (isPalindrome(sub)) {
                    // cout << "Palindrom: " << sub << endl;
                    // cout << "Length: " << sub.length() << endl;
                    return sub.length();
                }
            }
            return 0;
        }
        int L = 0, R = 0;
        L = allSubsequences(i + 1, s, sub);
        sub += s[i];
        R = allSubsequences(i + 1, s, sub);
        return max(L, R);
    }
    
    // Checks if s is palindrome
    bool isPalindrome(string &s) {
        int size = s.size();
        for (int i = 0; i < size / 2; i++) {
            if (s[i] != s[size - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
