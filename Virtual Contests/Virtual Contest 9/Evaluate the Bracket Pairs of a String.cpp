// Question Link: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for (vector<string> &k : knowledge) {
            map[k[0]] = k[1];
        }
        
        int len = s.size();
        string res = "";
        
        for (int i = 0; i < len; i++) {
            if (s[i] != '(') {
                res += s[i];
            }
            else {
                string key = "";
                int j = i + 1;
                
                for (; j < len && s[j] != ')'; j++) {
                    key += s[j];
                }
                
                if (map.find(key) != map.end()) {
                    res += map[key];
                }
                
                else {
                    res += "?";
                }
                
                i = j;
            }
        }
        
        return res;
    }
};