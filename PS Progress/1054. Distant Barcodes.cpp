// Question Link: https://leetcode.com/problems/distant-barcodes/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> result;
        unordered_map<int, int> barcodeFrequencyMap;
        for (int barcode : barcodes) {
            barcodeFrequencyMap[barcode]++;
        }
        priority_queue<pair<int, int>> toDo;
        for (auto it : barcodeFrequencyMap) {
            toDo.push({it.second, it.first});
        }
        while (!toDo.empty()) {
            pair<int, int> cur1 = toDo.top(), cur2;
            toDo.pop();
            result.push_back(cur1.second);
            cur1.first--;
            if (!toDo.empty()) {
                cur2 = toDo.top();
                toDo.pop();
                result.push_back(cur2.second);
                cur2.first--;
            }
            if (cur1.first > 0) {
                toDo.push(cur1);
            }
            if (cur2.first > 0) {
                toDo.push(cur2);
            }
        }
        return result;
    }
};