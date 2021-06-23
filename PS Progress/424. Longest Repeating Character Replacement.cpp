// Question Link: https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        int L = 0, R = 0;
        int countsMap[26] = { 0 };
        int uniqueCount = 0;
        // Max letter freq
        int maxCharFreq = 0;
        char maxChar = '\0';
        int result = 0;
        for (; R < len; R++) {
            // Update counts map
            countsMap[s[R] - 'A']++;
            // Update max char freq with new updated letter freq
            updateMaxLetterFreq(s, R, countsMap, maxCharFreq, maxChar);
            // Update unique count
            uniqueCount = getUniqueCount(countsMap, maxChar);
            // Check if window is invalid
            if (uniqueCount > k) {
                // Update counts map
                countsMap[s[L] - 'A']--;
                L++;
                // Update max char freq with new updated letter freq
                updateMaxLetterFreq(s, R, countsMap, maxCharFreq, maxChar);
                // Update unique count
                uniqueCount = getUniqueCount(countsMap, maxChar);
            }
        }
        // Update the result
        result = max(result, R - L);
        return result;
    }
    
    // Update max char freq with new updated letter freq
    void updateMaxLetterFreq(string &s, int &R, int countsMap[], int &maxCharFreq, char &maxChar) {
        if (countsMap[s[R] - 'A'] > maxCharFreq) {
            maxCharFreq = countsMap[s[R] - 'A'];
            maxChar = s[R];
        }
    }
    
    // Count number of occurences except max freq letter
    int getUniqueCount(int countsMap[], char maxChar) {
        int newCount = 0;
        for (int i = 0; i < 26; i++) {
            if (countsMap[i] > 0) {
                char c = i + 'A';
                if (c != maxChar) {
                    newCount += countsMap[i];
                }
            }
        }
        return newCount;
    }
};