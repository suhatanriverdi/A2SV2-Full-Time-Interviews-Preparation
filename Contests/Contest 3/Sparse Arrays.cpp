// Question Link: https://www.hackerrank.com/contests/a2sv-contest-3/challenges/sparse-arrays

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    unordered_map<string, int> mp;
    for (string s : strings) {
        mp[s]++;
    }
    vector<int> result(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++) {
        if (mp.find(queries[i]) != mp.end()) {
            result[i] += mp[queries[i]];
        }
    }
    return result;
}