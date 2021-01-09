// Question Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// Concise Stack Solution
class Solution {
public:
    /*
    abbaca
    res = a
    res = ab
    res = abb
    */
    string removeDuplicates(string S) {
        if (S.size() == 1) {
            return S;
        }
        string result;
        for (char &c : S) {
            if (result.size() > 0 && result.back() == c) {
                result.pop_back();
            } else {
                result += c;
            }
        }
        return result;
    }
};


// We can consider strings as stacks as well
class Solution {
public:
    /*
    abbaca
    abbac a
    abba ca
    abb aca
    ab baca -> b == b
    a aca -> a == a
    */
    string removeDuplicates(string S) {
        if (S.size() == 1) {
            return S;
        }
        string result;
        while (S.size() > 0) {
            result += S.back();
            S.pop_back();
            while (S.size() > 0 && result.size() > 0 && result.back() == S.back()) {
                S.pop_back();
                result.pop_back();
            }
        }
        reverse(begin(result), end(result));
        return result;
    }
};

// Straight Forward Greedy Solution
class Solution {
public:
    string removeDuplicates(string S) {
        if (S.size() == 1) {
            return S;
        }
        string result;
        bool dupFound = true;
        while (dupFound) {
            dupFound = false;
            for (int i = 1; i < S.size(); i++) {
                if (S[i] == S[i - 1]) {
                    S[i] = S[i - 1] = '*';
                    dupFound = true;
                }
            }
            result = "";
            for (char c : S) {
                if (c != '*') {
                    result += c;    
                }
            }
            S = result;
        }
        return result;
    }
};
