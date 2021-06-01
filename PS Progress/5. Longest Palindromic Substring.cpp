// Question Link: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int memo[1001][1001];
        memset(memo, -1, sizeof(memo));
        vector<int> answer = {0, 0, 1};
        helper(0, s.size() - 1, s, memo, answer);
        return s.substr(answer[0], answer[2]);
    }
    
    bool helper(int l, int r, string &s, int memo[][1001], vector<int> &answer) {
        if (memo[l][r] != -1) {
            return memo[l][r];         
        }
        
        if (l >= r) {
            return true;
        }
        
        // Possible palindrome beginning
        bool found = false;
        if (s[l] == s[r]) {
            found = true && helper(l + 1, r - 1, s, memo, answer);
        }
        
        // Try other possibilities
        helper(l + 1, r , s, memo, answer);
        helper(l, r - 1, s, memo, answer);
        
        // Update longest palindrome position and width
        if (found && (r - l + 1) > answer[2]) {
            answer = {l, r, (r - l + 1)};
        }
        
        // Memoization
        memo[l][r] = found;
        // cout << "L: " << l << " r: " << r << " found?: " << memo[l][r] << endl;
        
        return found;
    }
};