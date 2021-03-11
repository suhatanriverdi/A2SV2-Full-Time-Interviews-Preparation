// Question Link: https://leetcode.com/problems/bag-of-tokens/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int size = tokens.size(), maxScore = 0, score = 0, L = 0;
        if (size == 0) {
            return maxScore;
        }
        sort(begin(tokens), end(tokens));
        // First, try to get as many score as possible
        while (L < size && P >= tokens[L]) {
            while (L < size && P >= tokens[L]) {
                P -= tokens[L++];
                score++;
                maxScore = max(maxScore, score);
            }
            // Then try to maximize power
            if (!tokens.empty() && maxScore > 0) {
                P += tokens.back();
                tokens.pop_back();
                score--;
            }
        }
        return maxScore;
    }
};
