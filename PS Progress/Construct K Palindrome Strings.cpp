// Question Link: https://leetcode.com/problems/construct-k-palindrome-strings/

class Solution {
public:
    bool canConstruct(string s, int k) {
        int counts[26] = { 0 };
        for (char c : s) {
            counts[c - 'a']++;
        }
        int oddSum = 0;
        int evenSum = 0;
        int numberOfOdds = 0;
        int numberOfEvens = 0;
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 0) {
                if (counts[i] % 2 == 1) {
                    oddSum += counts[i];
                    numberOfOdds++;
                }
                else {
                    evenSum += counts[i];
                    numberOfEvens++;
                }
            }
        }
        return (numberOfEvens == 0 && k >= numberOfOdds && k <= oddSum) || (numberOfOdds == 0 && k <= evenSum)
            || (numberOfEvens != 0 && numberOfOdds != 0 && k >= numberOfOdds && k <= oddSum + evenSum);
    }
};