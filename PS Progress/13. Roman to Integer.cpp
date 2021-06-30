// Question Link: https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbolValueMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        // Check the 6 instances first
        /*
        I before V (5) and X (10) to make 4 and 9. 
        X before L (50) and C (100) to make 40 and 90. 
        C before D (500) and M (1000) to make 400 and 900.
        */
        int resultInt = 0;
        int len = s.size();
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == 'I' && i + 1 < len) {
                if (s[i + 1] == 'V') {
                    resultInt += 4;
                    s[i + 1] = '*';
                    s[i] = '*';
                }
                else if (s[i + 1] == 'X') {
                    resultInt += 9;
                    s[i + 1] = '*';
                    s[i] = '*';
                }
            }
            if (s[i] == 'X' && i + 1 < len) {
                if (s[i + 1] == 'L') {
                    resultInt += 40;
                    s[i + 1] = '*';
                    s[i] = '*';
                }
                else if (s[i + 1] == 'C') {
                    resultInt += 90;
                    s[i + 1] = '*';
                    s[i] = '*';
                }
            }
            if (s[i] == 'C' && i + 1 < len) {
                if (s[i + 1] == 'D') {
                    resultInt += 400;
                    s[i + 1] = '*';
                    s[i] = '*';
                }
                else if (s[i + 1] == 'M') {
                    resultInt += 900;
                    s[i + 1] = '*';
                    s[i] = '*';
                }
            }
        }
        
        for (char c : s) {
            if (c != '*') {
                resultInt += symbolValueMap[c];
            }
        }
        
        return resultInt;
    }
};