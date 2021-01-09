// Question Link: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> pStack;
        unordered_map<char, char> pMap = {
            {')', '('},
            {']', '['},  
            {'}', '{'}  
        };
        if (s.size() >= 1 && (s[0] == ')' || s[0] == ']' || s[0] == '}')) {
            return false;
        }
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                pStack.push(c);
            } else {
                if (pStack.empty() || pMap[c] != pStack.top()) {
                    return false;
                }
                pStack.pop();
            }
        }
        return pStack.empty();
    }
};
