// Question Link: https://leetcode.com/problems/find-and-replace-pattern/

// Alternative Solution
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> result;
        pattern = getPattern(pattern);
        for (string &word : words) {
            string wordPattern = getPattern(word);
            // Checks if strings contains each other
            if (pattern.find(wordPattern) != std::string::npos ||
               wordPattern.find(pattern) != std::string::npos) {
                result.push_back(word);
            }
        }
        return result;
    }
    
    // Creates a pattern for input string
    string getPattern(string &s) {
        unordered_map<char, char> patternMap;
        char key = '0';
        for (char c : s) {
            if (patternMap.find(c) == patternMap.end()) {
                patternMap[c] = key;
                key++;
            }
        }
        string pattern = "";
        for (char c : s) {
            pattern += patternMap[c];
        }
        return pattern;
    }
};

// Two Maps Solution
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> result;
        for (string &word : words) {
            if (matches(pattern, word)) {
                result.push_back(word);
            }
        }
        return result;
    }
    
    bool matches(string &p, string &w) {
        unordered_map<char, char> wordMap, patternMap;
        for (int i = 0; i < w.size(); i++) {
            if (wordMap.find(w[i]) == wordMap.end()) {
                wordMap[w[i]] = p[i];
            }
            if (patternMap.find(p[i]) == patternMap.end()) {
                patternMap[p[i]] = w[i];
            }
            if (wordMap[w[i]] != p[i] || patternMap[p[i]] != w[i]) {
                return false;
            }
        }
        return true;
    }
};
