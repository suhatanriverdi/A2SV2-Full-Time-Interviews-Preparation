// Question Link: https://leetcode.com/problems/making-file-names-unique/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> namesMap; // {name, next prefix number}
        string newWord = "";
        for (int i = 0; i < names.size(); i++) {
            if (namesMap.find(names[i]) == namesMap.end()) {
                namesMap[names[i]] = 1;
            }
            else {
                for (int nextPrefixNum = namesMap[names[i]]++; nextPrefixNum < 50001; nextPrefixNum++) {
                    newWord = names[i] + "(" + to_string(nextPrefixNum) + ")";
                    if (namesMap.find(newWord) == namesMap.end()) {
                        namesMap.insert({newWord, 1});
                        names[i] = newWord;
                        break;
                    }
                }
            }
        }
        return names;
    }
};