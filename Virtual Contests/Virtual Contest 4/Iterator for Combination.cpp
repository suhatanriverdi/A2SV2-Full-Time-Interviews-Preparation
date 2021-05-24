// Question Link: https://leetcode.com/problems/iterator-for-combination

class CombinationIterator {
    int index, len, combLen;
    string s;
    vector<string> allCombs;
public:
    CombinationIterator(string characters, int combinationLength) {
        index = 0;
        s = characters;
        combLen = combinationLength;
        len = characters.size();
        // Get all combinations
        string comb = "";
        getAllCombs(0, comb);
    }
    
    void getAllCombs(int cur, string comb) {
        // Desired combs
        if (comb.size() == combLen) {
            if (allCombs.empty() || (!allCombs.empty() && comb != allCombs.back())) {
                allCombs.push_back(comb);
            }
        }
        // One of the combs, save it to allCombs
        if (cur == len) {
            return;
        }
        // Include
        comb += s[cur];
        getAllCombs(cur + 1, comb);
        // Exclude
        comb.pop_back();
        getAllCombs(cur + 1, comb);
    }
    
    string next() {
        return allCombs[index++];
    }
    
    bool hasNext() {
        return index < allCombs.size();
    }
};