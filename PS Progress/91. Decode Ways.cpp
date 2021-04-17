// Question Link: https://leetcode.com/problems/decode-ways/

// Top-Down DP Solution
class Solution {
    unordered_map<string, int> memo;
public:
    int numDecodings(string s) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        if (s.size() == 0) {
            return 1;
        }
        
        int one = 0, two = 0;
        // Take 1 digit
        if (s[0] >= '1' && s[0] <= '9') {
            one += numDecodings(s.substr(1, s.size() - 1));
        }
        
        // Take 2 digit, consider: 10 - 26
        int twoDigit = stoi(s.substr(0, 2));
        if (twoDigit >= 10 && twoDigit <= 26) {
            two += numDecodings(s.substr(2, s.size() - 2));
        }
        
        memo[s] = one + two;
        return memo[s];
    }
};