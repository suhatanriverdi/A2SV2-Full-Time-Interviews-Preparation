// Question Link: https://leetcode.com/problems/most-common-word/

class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        unordered_set<string> ban(begin(banned), end(banned));
        for (int i = 0; i < p.size(); i++) {
            p[i] = tolower(p[i]);
        }
        string clean = "";
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == ' ' || p[i] == '!' || p[i] == '?' || p[i] == '\'' || p[i] == ',' || p[i] == ';' || p[i] == '.') {
                clean += ' ';
            }
            if (isalpha(p[i])) {
                clean += p[i];
            }
        }
        unordered_map<string, int> mostFreq;
        istringstream iss(clean);
        string word;
        while(iss >> word) {
            if (ban.find(word) == ban.end()) {
                mostFreq[word]++;
            }
        }
        int maxFreq = 0;
        string result = "";
        for (auto it : mostFreq) {
            if (it.second > maxFreq) {
                result = it.first;
                maxFreq = it.second;
            }
        }
        return result;
    }
};
