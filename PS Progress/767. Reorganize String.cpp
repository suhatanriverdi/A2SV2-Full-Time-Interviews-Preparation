// Question Link: https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string S) {
        if (S.size() <= 1) {
            return S;
        }
        unordered_map<char, int> frequencyMap;
        for (char c : S) {
            frequencyMap[c]++;
        }
        priority_queue<pair<int, char>> freqCharPQ;
        for (auto it : frequencyMap) {
            freqCharPQ.push({it.second, it.first});
        }
        string result;
        while (!freqCharPQ.empty()) {
            pair<int, char> cur1 = freqCharPQ.top(), cur2;
            freqCharPQ.pop();
            result += cur1.second;
            cur1.first--;
            if (freqCharPQ.size() > 0) {
                cur2 = freqCharPQ.top();
                freqCharPQ.pop();
                result += cur2.second;
                cur2.first--;
            }
            if (result.back() == result[result.size() - 2]) {
                return "";
            }
            if (cur1.first > 0) {
                freqCharPQ.push(cur1);
            }
            if (cur2.first > 0) {
                freqCharPQ.push(cur2);
            }
        }
        return result;
    }
};