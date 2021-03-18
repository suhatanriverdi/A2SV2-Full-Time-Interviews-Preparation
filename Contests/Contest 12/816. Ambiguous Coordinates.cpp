// Question Link: https://leetcode.com/problems/ambiguous-coordinates/

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        // First get rid of paranthesis at the both end
        S.erase(0, 1);
        S.pop_back();
        vector<string> result;
        vector<pair<string, string>> valids;
        int size = S.size();
        // Without dots
        for (int i = 0; i < size - 1; i++) {
            string A = S.substr(0, i + 1);
            string B = S.substr(i + 1, size - i + 1);
            valids.push_back({A, B});
        }
        // With Dots
        for (int i = 0; i < valids.size(); i++) {
            vector<string> left = { valids[i].first }, right = { valids[i].second };
            if (valids[i].first.size() > 1) {
                for (int j = 1; j < valids[i].first.size(); j++) {
                    string withDotL = valids[i].first;
                    withDotL.insert(j, 1, '.');
                    left.push_back(withDotL);
                }
            }
            if (valids[i].second.size() > 1) {
                for (int j = 1; j < valids[i].second.size(); j++) {
                    string withDotR = valids[i].second;
                    withDotR.insert(j, 1, '.');
                    right.push_back(withDotR);
                }
            }
            // Start checking validity
            for (int i = 0; i < left.size(); i++) {
                for (int j = 0; j < right.size(); j++) {
                    if (isValid(left[i]) && isValid(right[j])) {
                        result.push_back("(" + left[i] + ", " + right[j] + ")");
                    }
                }
            }
        }
        return result;
    }
    
    // Valid 0, 0.X
    // Invalid: "5.0", "00", "0.0", "0.00", "1.0", "001", "00.01"
    bool isValid(string &s) {
        // Single char
        if (s.size() == 1) {
            return true;
        }
        // Invalid case: 0xxx0
        if (s[0] == '0') {
            // Only valid 0.xxx
            if (s[1] != '.') {
                return false;
            }
            // 00, 0xx0
            if (s.back() == '0' || s[1] == '0') {
                return false;
            }
            return true;
        }
        // Invalid case: xxx.0
        if (s.back() == '0') {
            // Only valid case xxx0
            if (s.find('.') == std::string::npos) {
                return true;
            }
            return false;
        }
        return true;
    }
};
