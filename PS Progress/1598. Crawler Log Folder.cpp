// Question Link: https://leetcode.com/problems/crawler-log-folder/
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        for (string log : logs) {
            // Move to the parent folder
            if (log[0] == '.') {
                if (log[1] == '.' && result > 0) {
                    result--;
                }
            }
            // Move to the child folder
            else {
                result++;
            }
        }
        return result;
    }
};
