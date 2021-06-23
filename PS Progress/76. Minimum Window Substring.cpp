// Question Link: https://leetcode.com/problems/minimum-window-substring

// A bit optimized Solution, We don't need to use sorted map
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) {
            return "";
        }
        
        unordered_map<char, int> mapS, mapT;
        // Fill map t and remaining
        for (char c : t) {
            mapT[c]++;
        }
        
        // Expand the first window on S to the right
        int L = 0, R = 0;
        for (; R < m; R++) {
            if (mapT.find(s[R]) != mapT.end()) {
                mapS[s[R]]++;
            }
            if (hasWindowAllChars(mapS, mapT)) {
                break;
            }
        }
        
        if (hasWindowAllChars(mapS, mapT) == false) {
            return "";
        }
        
        // Minimum Window found so far
        vector<int> minAns = { R - L + 1, L, R };
        
        // Sliding window on S
        while (R < m) {
            // We have a window with all the characters, we can L++
            bool hasAllChars = hasWindowAllChars(mapS, mapT);
            if (hasAllChars) {
                // We ignore all the other chars that are not in t
                if (mapT.find(s[L]) != mapT.end()) {
                    mapS[s[L]]--;
                }
                // Update answer window
                if (R - L + 1 < minAns[0]) {
                    minAns = { R - L + 1, L, R };
                }
                L++;
            }
            // Expand window
            else {
                R++;
                if (mapT.find(s[R]) != mapT.end()) {
                    mapS[s[R]]++;
                }
            }
        }
        
        return string(s.begin() + minAns[1], s.begin() + minAns[2] + 1);
    }
    
    int hasWindowAllChars(unordered_map<char, int> &mapS, unordered_map<char, int> &mapT) {
        if (mapS.size() != mapT.size()) {
            return false;
        }
        for (auto &it : mapS) {
            if (it.second < mapT[it.first]) {
                return false;
            }
        }
        return true;
    }
};

// Initial Solution
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) {
            return "";
        }
        
        map<char, int> mapS, mapT;
        // Fill map t and remaining
        for (char c : t) {
            mapT[c]++;
        }
        
        // Expand the first window on S to the right
        int L = 0, R = 0;
        for (; R < m; R++) {
            if (mapT.find(s[R]) != mapT.end()) {
                mapS[s[R]]++;
            }
            if (hasWindowAllChars(mapS, mapT)) {
                break;
            }
        }
        
        if (hasWindowAllChars(mapS, mapT) == false) {
            return "";
        }
        
        // Minimum Window found so far
        vector<int> minAns = { R - L + 1, L, R };
        
        // Sliding window on S
        while (R < m) {
            // We have a window with all the characters, we can L++
            bool hasAllChars = hasWindowAllChars(mapS, mapT);
            if (hasAllChars) {
                // We ignore all the other chars that are not in t
                if (mapT.find(s[L]) != mapT.end()) {
                    mapS[s[L]]--;
                }
                // Update answer window
                if (R - L + 1 < minAns[0]) {
                    minAns = { R - L + 1, L, R };
                }
                L++;
            }
            // Expand window
            else {
                R++;
                if (mapT.find(s[R]) != mapT.end()) {
                    mapS[s[R]]++;
                }
            }
        }
        
        return string(s.begin() + minAns[1], s.begin() + minAns[2] + 1);
    }
    
    int hasWindowAllChars(map<char, int> &mapS, map<char, int> &mapT) {
        if (mapS.size() != mapT.size()) {
            return false;
        }
        for (auto &it : mapS) {
            if (it.second < mapT[it.first]) {
                return false;
            }
        }
        return true;
    }
};
