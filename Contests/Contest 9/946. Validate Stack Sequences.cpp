// Question Link: https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> validateStack;
        int popIndex = 0;
        for (int &p : pushed) {
            validateStack.push(p);
            while (!validateStack.empty() && popped[popIndex] == validateStack.top()) {
                validateStack.pop();
                popIndex++;
            }
        }
        return validateStack.empty();
    }
};
