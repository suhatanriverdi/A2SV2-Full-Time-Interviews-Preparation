// Question Link: https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int carry = 0, sum = 0;
        while (!num1.empty() || !num2.empty()) {
            int d1 = 0;
            if (!num1.empty()) {
                d1 = num1.back() - '0';
                num1.pop_back();
            }
            
            int d2 = 0;
            if (!num2.empty()) {
                d2 = num2.back() - '0';
                num2.pop_back();
            }
            
            sum = d1 + d2 + carry;
            carry = (sum >= 10) ? 1 : 0;
            res += (sum % 10) + '0';
        }
        
        if (carry) {
            res += '1';
        }
        reverse(begin(res), end(res));
        return res;
    }
};