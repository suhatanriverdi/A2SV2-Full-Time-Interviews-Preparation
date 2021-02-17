// Question Link: https://leetcode.com/problems/word-ladder

// Solution 0
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(begin(wordList), end(wordList)), seen;
        // If endWord is not in the list, we cannot reach to the end
        if (words.find(endWord) == words.end()) {
            return 0;
        }
        // Build the graph
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> graph; // {word, {neighbor words}}
        for (string &word : wordList) {
            string originalWord = word;
            for (int i = 0; i < word.size(); i++) {
                char originalLetter = word[i];
                word[i] = '*';
                graph[originalWord].push_back(word);
                graph[word].push_back(originalWord);
                word[i] = originalLetter;
            }
        }
        // Run Bfs
        queue<pair<string, int>> todo; // {word, step}
        todo.push({beginWord, 0});
        seen.insert(beginWord);
        while (!todo.empty()) {
            pair<string, int> cur = todo.front();
            todo.pop();
            if (cur.first == endWord) {
                return (cur.second / 2) + 1;
            }
            // Get the all transformations can be formed from current word
            for (string &neighbor : graph[cur.first]) {
                if (seen.find(neighbor) == words.end()) {
                    todo.push({neighbor, cur.second + 1});
                    seen.insert(neighbor);
                }
            }
        }        
        return 0;
    }
};

// Solution 1
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(begin(wordList), end(wordList)), seen;
        // If endWord is not in the list, we cannot reach to the end
        if (words.find(endWord) == words.end()) {
            return 0;
        }
        queue<pair<string, int>> todo; // {word, step}
        todo.push({beginWord, 1});
        while (!todo.empty()) {
            pair<string, int> cur = todo.front();
            todo.pop();
            if (cur.first == endWord) {
                return cur.second;
            }
            // Get the all transformations can be formed from current word
            string originalWord = cur.first;
            for (int i = 0; i < cur.first.size(); i++) {
                for (char l = 'a'; l <= 'z'; l++) {
                    cur.first[i] = l;
                    if (words.find(cur.first) != words.end() && seen.find(cur.first) == words.end()) {
                        todo.push({cur.first, cur.second + 1});
                        seen.insert(cur.first);
                    }
                }
                // Get back to the original word for next steps
                cur.first = originalWord;
            }
        }
        return 0;
    }
};

// Solution 2
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(begin(wordList), end(wordList)), seen;
        // If endWord is not in the list, we cannot reach to the end
        if (words.find(endWord) == words.end()) {
            return 0;
        }
        queue<pair<string, int>> todo; // {word, step}
        todo.push({beginWord, 1});
        while (!todo.empty()) {
            pair<string, int> cur = todo.front();
            todo.pop();
            if (cur.first == endWord) {
                return cur.second;
            }
            // Get the all transformations can be formed from current word
            for (int c = 0; c < cur.first.size(); c++) {
                string up = cur.first, down = cur.first;
                while (islower(++up[c])) {
                    if (words.find(up) != words.end() && seen.find(up) == words.end()) {
                        todo.push({up, cur.second + 1});
                        seen.insert(up);
                    }
                }
                while (islower(--down[c])) {
                    if (words.find(down) != words.end() && seen.find(down) == words.end()) {
                        todo.push({down, cur.second + 1});
                        seen.insert(down);
                    }
                }
            }
        }
        return 0;
    }
};
