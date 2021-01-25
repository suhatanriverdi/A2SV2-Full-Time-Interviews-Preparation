// Question Link: https://leetcode.com/problems/top-k-frequent-elements

// O(log k)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> Map; // Counts
        auto comp = [](pair<int, string> &a, pair<int, string> &b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> PQ(comp);
        for (string &word : words) {
            Map[word]++;
        }
        for (auto it : Map) {
            PQ.push({it.second, it.first});
            if (PQ.size() > k) {
                PQ.pop();
            }
        }
        vector<string> result;
        while (!PQ.empty()) {
            result.push_back(PQ.top().second);
            PQ.pop();
        }
        reverse(begin(result), end(result));
        return result;
    }
};

// O(log n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> Map; // Counts
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> PQ; // Min Heap
        for (int &n : nums) {
            Map[n]++;
        }
        for (auto it : Map) {
            if (PQ.size() < k) {
                PQ.push({it.second, it.first});
            } else {
                if (it.second > PQ.top()[0]) {
                    PQ.pop();
                    PQ.push({it.second, it.first});
                }  
            }
        }
        vector<int> result;
        while (!PQ.empty()) {
            result.push_back(PQ.top()[1]);
            PQ.pop();
        }
        return result;
    }
};
