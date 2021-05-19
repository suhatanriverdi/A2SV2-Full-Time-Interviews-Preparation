// Question Link: https://leetcode.com/problems/number-of-atoms/

struct item {
    string name = "";
    int count = 0;
};

class Solution {
public:
    string countOfAtoms(string formula) {
        // "((O2H)2)3" -> "( + ( + O2 + H + ) * 2 ) * 3"
        vector<item> items = parseString(formula);
        stack<item> itemStack;
        for (int i = 0; i < items.size(); i++) {
            // While item is not closing paranheses
            if (items[i].name != ")") {
                itemStack.push(items[i]);
            }
            // ')' Closing paranheses, do calculations
            else if (i + 1 < items.size() && isdigit(items[i + 1].name[0])) {
                int multiplyBy = stoi(items[i + 1].name);
                vector<item> tmpItems;
                while (!itemStack.empty() && itemStack.top().name != "(") {
                    item cur = itemStack.top();
                    itemStack.pop();
                    cur.count *= multiplyBy;
                    tmpItems.push_back(cur);
                }
                // Pop the last seen '(' too
                itemStack.pop();
                // Push modified items to stack
                for (item &it : tmpItems) {
                    itemStack.push(it);
                }
                // Update i
                i += 1;
            }
        }
        map<string, int> map;
        // Pop all items and save counts
        for (; !itemStack.empty(); itemStack.pop()) {
            if (isalpha(itemStack.top().name[0])) {
                map[itemStack.top().name] += itemStack.top().count;
            }
        }
        string result = "";
        // Print map
        for (auto &it : map) {
            result += it.first;
            // If count > 1
            if (it.second > 1) {
                result += to_string(it.second);
            }
        }
        return result;
    }
    
    // Parses a formula into items: "((O2H)2)3" -> "( + ( + O2 + H + ) * 2 ) * 3"
    vector<item> parseString(string &formula) {
        vector<item> items;
        for (int i = 0; i < formula.size(); i++) {
            // Parantheses '(' or ')', and Digits after parantheses
            if (formula[i] == '(' || formula[i] == ')') {
                items.push_back({string(1, formula[i]), -1});
            }
            // Starting of a new atom A - Z
            else if (isupper(formula[i])) {
                item newAtom = {string(1, formula[i]), 1};
                int atomIdx = i + 1;
                // Parse name
                while (atomIdx < formula.size() && islower(formula[atomIdx])) {
                    newAtom.name += formula[atomIdx];
                    atomIdx++;
                }
                // Parse digits/count
                string digits = "";
                while (atomIdx < formula.size() && isdigit(formula[atomIdx])) {
                    digits += formula[atomIdx];
                    atomIdx++;
                }
                // Check if any digits found
                if (digits.empty() == false) {
                    newAtom.count = stoi(digits);
                }
                // Push new atom to items
                items.push_back(newAtom);
                // Update i
                i = atomIdx - 1;
            }
            // Parse counts after parantheses ..)99..
            else if (isdigit(formula[i])) {
                string count = string(1, formula[i]);
                int atomIdx = i + 1;
                while (atomIdx < formula.size() && isdigit(formula[atomIdx])) {
                    count += formula[atomIdx];
                    atomIdx++;
                }
                items.push_back({count, -1});
                // Update i
                i = atomIdx - 1;
            }
        }
        return items;
    }
};