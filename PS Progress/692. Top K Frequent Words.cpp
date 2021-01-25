// Question Link: https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> Map; // Counts
        auto comp = [](pair<int, string> &a, pair<int, string> &b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> PQ(comp);
        for (string &word : words) {
            Map[word]++;
        }
        for (auto it : Map) {
            PQ.push({it.second, it.first});
        }
        vector<string> result;
        while (!PQ.empty() && k--) {
            result.push_back(PQ.top().second);
            PQ.pop();
        }
        return result;
    }
};