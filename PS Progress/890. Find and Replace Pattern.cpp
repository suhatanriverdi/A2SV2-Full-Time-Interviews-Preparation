// Question Link: https://leetcode.com/problems/find-and-replace-pattern/

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