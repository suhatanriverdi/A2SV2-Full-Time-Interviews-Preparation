// Question Link: https://leetcode.com/problems/simplify-path/

// Solution 1.1 Removed Comments
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();
        deque<string> unitDeck;
        for (int i = 0; i < len; i++) {
            // Initialize unit
            string unit = "/";
            // Check the next char                
            if (i + 1 < len && (path[i + 1] == '_' || isalpha(path[i + 1]))) {
                // Get the whole unit
                int idx = i + 1;
                while (idx < len && path[idx] != '/') {
                    unit += path[idx];
                    idx++;
                }
                // Update i
                i = idx;
                i--;
                // Push valid unit to the stack
                unitDeck.push_back(unit);
            }
            // if next char is '.' count the dots and deteck the patter do we have '.' , '..' or '...'
            else if (path[i + 1] == '.') {
                // Get the whole dots
                int idx = i + 1;
                // Get the unit till the other slash or end
                while (idx < len && path[idx] != '/') {
                    unit += path[idx];
                    idx++;
                }
                // Update i
                i = idx;
                i--;
                // Check the dots
                // "/.." means we need to go up, so we pop
                if (unit == "/..") {
                    // Go to one up dir
                    if (unitDeck.empty() == false) {
                        unitDeck.pop_back();
                    }
                }
                // "/..." -> this is a unit(dir or file) as well
                else if (unit != "/.") {
                    unitDeck.push_back(unit);
                }
            }
        }
        // Clear the stack and build the simplified canonical path
        string simplifiedCanonicalPath = "";
        for (; !unitDeck.empty(); unitDeck.pop_front()) {
            simplifiedCanonicalPath += unitDeck.front();
        }
        return (simplifiedCanonicalPath == "" ? "/" : simplifiedCanonicalPath);
    }
};

// Solution 1 Long Version
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();
        deque<string> unitDeck;
        //   01234
        // " /a/// "
        //    ^
        for (int i = 0; i < len; i++) {
            // Initialize unit
            string unit = "/";
            // Check the next char                
            if (i + 1 < len && (path[i + 1] == '_' || isalpha(path[i + 1]))) {
                // Get the whole unit
                int idx = i + 1;
                while (idx < len && path[idx] != '/') {
                    unit += path[idx];
                    idx++;
                }
                // Update i
                i = idx;
                i--;
                // Push valid unit to the stack
                unitDeck.push_back(unit);
            }
            // if next char is '.' count the dots and deteck the patter do we have '.' , '..' or '...'
            else if (path[i + 1] == '.') {
                // Get the whole dots
                int idx = i + 1;
                // Get the unit till the other slash or end
                while (idx < len && path[idx] != '/') {
                    unit += path[idx];
                    idx++;
                }
                // Update i
                i = idx;
                i--;
                // Check the dots
                // "/." means do nothing just ignore
                if (unit == "/.") {
                    
                }
                // "/.." means we need to go up, so we pop
                else if (unit == "/..") {
                    // Go to one up dir
                    if (unitDeck.empty() == false) {
                        unitDeck.pop_back();
                    }
                }
                // "/..." -> this is a unit(dir or file) as well
                else {
                    unitDeck.push_back(unit);
                }
            }
            // if next char is '/', just ignore it and continue
            else {
                
            } 
        }
        // Clear the stack and build the simplified canonical path
        string simplifiedCanonicalPath = "";
        for (; !unitDeck.empty(); unitDeck.pop_front()) {
            simplifiedCanonicalPath += unitDeck.front();
        }
        return (simplifiedCanonicalPath == "" ? "/" : simplifiedCanonicalPath);
    }
};

// Solution 2 Shorter Version
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();
        deque<string> unitDeck;
        for (int i = 0; i < len; i++) {
            // Check the next char                
            if (i + 1 < len && (path[i + 1] == '_' || isalpha(path[i + 1]))) {
                pair<string, int> unitPair = buildUnit(i, len, path);
                // Update i
                i = unitPair.second - 1;
                // Push valid unit to the stack
                unitDeck.push_back(unitPair.first);
            }
            // if next char is '.' count the dots and deteck the patter do we have '.' , '..' or '...'
            else if (path[i + 1] == '.') {
                pair<string, int> unitPair = buildUnit(i, len, path);
                // Update i
                i = unitPair.second - 1;
                // Check the dots
                // "/.." means we need to go up, so we pop
                if (unitPair.first == "/..") {
                    // Go to one up dir
                    if (unitDeck.empty() == false) {
                        unitDeck.pop_back();
                    }
                }
                // "/...", "/..asd" -> this is a unit(dir or file) as well
                else if (unitPair.first != "/.") {
                    unitDeck.push_back(unitPair.first);
                }
            }
        }
        // Clear the stack and build the simplified canonical path
        string simplifiedCanonicalPath = "";
        for (; !unitDeck.empty(); unitDeck.pop_front()) {
            simplifiedCanonicalPath += unitDeck.front();
        }
        return (simplifiedCanonicalPath == "" ? "/" : simplifiedCanonicalPath);
    }
    
    pair<string, int> buildUnit(int i, int &len, string &path) {
        string unit = "/";
        int idx = i + 1;
        while (idx < len && path[idx] != '/') {
            unit += path[idx];
            idx++;
        }
        return { unit, idx };
    }
};