// Question Link: https://leetcode.com/problems/word-ladder-ii/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end()), seen;
        vector<vector<string>> sequences;
        if (words.find(endWord) == words.end()) {
            return sequences;
        }
        unordered_map<string, unordered_set<string>> backtrackMap; // {word, where we came from}
        unordered_map<string, int> wordMaxLayerMap;
        int endLayer = INT_MAX; // We should know end layer for future prunings
        queue<pair<string, int>> todo; // {word, dist}
        todo.push({beginWord, 0});
        while (!todo.empty()) {
            pair<string, int> cur = todo.front();
            todo.pop();
            if (cur.first == endWord) {
                endLayer = cur.second; // Save end layer
            }
            for (int i = 0; i < cur.first.size(); i++) {
                string originalWord = cur.first;
                char originalLetter = cur.first[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    cur.first[i] = c;
                    if (endLayer != INT_MAX && (cur.second + 1 > endLayer)) {
                        break;
                    }
                    if (c != originalLetter && words.find(cur.first) != words.end()) {
                        if (wordMaxLayerMap.find(cur.first) == wordMaxLayerMap.end() || ((wordMaxLayerMap.find(cur.first) != wordMaxLayerMap.end() && cur.second + 1 <= wordMaxLayerMap[cur.first]))) {
                            todo.push({cur.first, cur.second + 1});
                            backtrackMap[cur.first].insert(originalWord);
                            wordMaxLayerMap[cur.first] = cur.second + 1;
                        }
                    }
                }
                cur.first[i] = originalLetter;
            }
        }
        if (backtrackMap.find(endWord) == backtrackMap.end()) {
            return sequences;
        }
        vector<string> path;
        extractSequence(backtrackMap, endWord, beginWord, sequences, path);
        for (vector<string> &sequence : sequences) {
            reverse(begin(sequence), end(sequence));
        }
        return sequences;
    }
    
    void extractSequence(unordered_map<string, unordered_set<string>> &backtrackMap, string &lastWord, string &beginWord, vector<vector<string>> &sequences, vector<string> &path) {
        path.push_back(lastWord);
        if (lastWord == beginWord) {
            sequences.push_back(path);
            path.pop_back();
            return;
        }
        for (auto backWord : backtrackMap[lastWord]) {
            extractSequence(backtrackMap, backWord, beginWord, sequences, path);
        }
        path.pop_back();
    }
};