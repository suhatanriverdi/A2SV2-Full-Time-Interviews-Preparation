// Question Link: https://leetcode.com/problems/word-break

// 0 ms
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(begin(wordDict), end(wordDict));
        set<int> sizes;
        for (string &word : wordDict) {
             sizes.insert(word.size());
        }
        int memo[301] = { -1 };
        memset(memo, -1, sizeof(memo));
        return helper(0, s, dict, sizes, memo);
    }
    
    int helper(int pos, string &s, unordered_set<string> &dict, set<int> &sizes, int memo[]) {
        if (memo[pos] != -1) {
            return memo[pos];
        }
        if (pos == s.size()) {
            return 1;
        }
        bool found = 0;
        for (auto &len : sizes) {
            int width = pos + len - 1;
            if (width >= s.size()) {
                break;
            }
            string sub = s.substr(pos, len);
            if (dict.find(sub) != dict.end()) {
                found |= helper(width + 1, s, dict, sizes, memo);
            }
        }
        memo[pos] = found;
        return found;
    }
};

// A bit optimized
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(begin(wordDict), end(wordDict));
        set<int> sizes;
        for (string &word : wordDict) {
             sizes.insert(word.size());
        }
        int memo[301][1001];
        memset(memo, -1, sizeof(memo));
        return helper(0, 0, s, dict, sizes, memo);
    }
    
    int helper(int pos, int width, string &s, unordered_set<string> &dict, set<int> &sizes, int memo[][1001]) {
        if (memo[pos][width] != -1) {
            return memo[pos][width];
        }
        if (pos == s.size()) {
            return 1;
        }
        bool found = 0;
        for (auto &len : sizes) {
            int width = pos + len - 1;
            if (width >= s.size()) {
                break;
            }
            string sub = s.substr(pos, len);
            if (dict.find(sub) != dict.end()) {
                found |= helper(width + 1, width, s, dict, sizes, memo);
            }
        }
        memo[pos][width] = found;
        return found;
    }
};

// Initial Solution with Memo
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(begin(wordDict), end(wordDict));
        unordered_set<int> sizes;
        for (string &word : wordDict) {
             sizes.insert(word.size());
        }
        int memo[301][1001];
        memset(memo, -1, sizeof(memo));
        return helper(0, 0, s, dict, sizes, memo);
    }
    
    int helper(int pos, int width, string &s, unordered_set<string> &dict, unordered_set<int> &sizes, int memo[][1001]) {
        if (memo[pos][width] != -1) {
            return memo[pos][width];
        }
        if (pos == s.size()) {
            return 1;
        }
        bool found = 0;
        for (auto &len : sizes) {
            int width = pos + len - 1;
            if (width < s.size()) {
                string sub = s.substr(pos, len);
                if (dict.find(sub) != dict.end()) {
                    found |= helper(width + 1, width, s, dict, sizes, memo);
                }
            }
        }
        memo[pos][width] = found;
        return found;
    }
};
