// Question Link: https://www.hackerrank.com/challenges/sherlock-and-valid-string

string isValid(string s) {
    int counts[26] = {0};
    for (char c : s) {
        counts[c - 'a']++;
    }
    unordered_set<int> freqSet;
    unordered_map<int, int> freqMap; //  {freq, amount}    
    for (int &count : counts) {
        if (count > 0) {
            freqMap[count]++;
            freqSet.insert(count);
        }
    }
    if (freqSet.size() == 1) {
        return "YES";
    }
    int a = *freqSet.begin();
    auto it = freqSet.begin();
    it++;
    int b = *it;
    if (freqSet.size() == 2) {
        if (freqMap[a] == 1 && (a - 1 == 0 || a - 1 == b)) {
            return "YES";
        }
        if (freqMap[b] == 1 && (b - 1 == 0 || b - 1 == a)) {
            return "YES";            
        }
    }
    return "NO";    
}