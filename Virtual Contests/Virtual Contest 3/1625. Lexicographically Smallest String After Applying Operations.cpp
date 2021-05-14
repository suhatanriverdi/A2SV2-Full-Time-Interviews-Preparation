// Question Link: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string lexSmallestString = s;
        unordered_set<string> seen = { s };
        queue<string> todo;
        todo.push(lexSmallestString);
        while (!todo.empty()) {
            string cur = todo.front();
            todo.pop();
            if (cur < lexSmallestString) {
                lexSmallestString = cur;
            }
            string rotated = shiftBtimes(cur, b);
            if (seen.find(rotated) == seen.end()) {
                todo.push(rotated);
                seen.insert(rotated);
            }
            addAToOdds(cur, a);
            if (seen.find(cur) == seen.end()) {
                todo.push(cur);
                seen.insert(cur);
            }
        }
        return lexSmallestString;
    }
    
    string shiftBtimes(string s, int b) {
        vector<char> moveToFront;
        while (b > 0) {
            moveToFront.push_back(s.back());
            s.pop_back();
            b--;
        }
        string shifted = "";
        for (int i = moveToFront.size() - 1; i >= 0; i--) {
            shifted += moveToFront[i];
        }
        for (char c : s) {
            shifted += c;
        }
        return shifted;
    }
    
    void addAToOdds(string &s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            int n = s[i] - '0';
            n = (a + n) % 10;
            s[i] = n + '0';
        }
    }
};