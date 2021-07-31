// Question Link: https://leetcode.com/problems/number-of-different-integers-in-a-string/

class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size();
        unordered_set<string> set;
        for (int i = 0; i < n; i++) {
            if (word[i] >= '0' && word[i] <= '9') {
                string num = "";
                num += word[i];
                
                int j = i + 1;
                for (; j < n && isdigit(word[j]); j++) {
                    num += word[j];
                }
                
                int idx = 0;
                for (; idx < num.size() && num[idx] == '0'; idx++) {}
                string clean = string(num.begin() + idx, num.end());
                set.insert(clean);
                
                i = j - 1;
            }
        }
        return set.size();
    }
};