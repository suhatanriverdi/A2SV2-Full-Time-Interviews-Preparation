// Question Link: https://leetcode.com/problems/longest-string-chain/

// Top Down DP with Memo
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int longestChainLen = 1;
        sort(begin(words), end(words), [] (string &a, string &b) { return a.size() < b.size(); });
        int memo[1001];
        memset(memo, -1, sizeof(memo));
        // For all words, start dfs
        for (int i = 0; i < words.size(); i++) {
            longestChainLen = max(dfs(i, words, memo), longestChainLen);
        }
        return longestChainLen;
    }
    
    int dfs(int prev, vector<string> &words, int memo[]) {
        if (memo[prev] != -1) {
            return memo[prev];
        }
        int answer = 1;
        for (int i = prev + 1; i < words.size(); i++) {
            if (words[i].size() - words[prev].size() > 1) {
                break;
            }
            if ((words[prev].size() + 1) == words[i].size() && isBPredecessorOfA(words[prev], words[i])) {
                answer = max(1 + dfs(i, words, memo), answer);
            }
        }
        // memoize the result
        memo[prev] = answer;
        return answer;
    }
    
    // Checks if B predecessor of A
    bool isBPredecessorOfA(string &a, string &b) {
        int i = 0;
        // Find first non-matching letter
        for (; i < a.size(); i++) {
            if (a[i] != b[i]) {
                break;
            }
        }
        for (int ai = i, bi = i + 1; ai < a.size(); ai++, bi++) {
            if (a[ai] != b[bi]) {
                return false;
            }
        }
        return true;
    }
};