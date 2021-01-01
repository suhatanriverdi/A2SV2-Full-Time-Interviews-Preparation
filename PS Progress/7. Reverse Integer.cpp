// Question Link: https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        // Value of INT_MAX is +2147483647
        // Value of INT_MIN is -2147483648
        string reversed = to_string(x);
        string intMax = to_string(INT_MAX);
        // Check negativity
        std::reverse(begin(reversed), end(reversed));
        if (x < 0) {
            reversed.pop_back();
            intMax.back()++; // Increase INT_MAX by 1 to 
        }
        // // Check possible overflow
        if (reversed.size() == 10) {
            for (int i = 0; i < reversed.size(); i++) {
                if (reversed[i] != intMax[i]) {
                    if ((reversed[i] - '0') > (intMax[i] - '0')) {
                        return 0;
                    }
                    break;
                }
            }
        }
        int result = stoi(reversed);
        if (x < 0) {
            result *= -1;
        }
        return result;
    }
};