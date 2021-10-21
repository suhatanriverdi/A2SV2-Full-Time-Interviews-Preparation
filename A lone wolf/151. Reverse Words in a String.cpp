// Question Link: https://leetcode.com/problems/reverse-words-in-a-string

// O(1) Space Solution
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int len = s.size(), head = 0;
        for (int i = 0; i < len; i++) {
            // Beginning of the word
            if (s[i] != ' ') {
                int begin = i, end = i;
                while (s[end] != ' ' && end < len) {
                    end++;
                }
                // Move end pointer to the exact end of the current word
                end--;
                // reverse the word itself
                reverseWord(begin, end, s);
                // Update pointer i
                i = end + 1;
                // Move reversed word to the beginning
                moveWordToHead(head, begin, end, len, s);
            }
        }
        
        // Clean the trailing spaces
        while (s.back() == ' ') {
            s.pop_back();
        }
        
        return s;
    }
    
    void moveWordToHead(int &head, int wordBegin, int wordEnd, int len, string &s) {
        while (wordBegin <= wordEnd) {
            // Move each letter to the beginning
            s[head] = s[wordBegin];
            // Clean the letters
            if (head != wordBegin) {
                s[wordBegin] = ' ';
            }
            head++;
            wordBegin++;
        }
        if (head < len) {
            s[head] = ' ';
            head++;
        }
    }
    
    void reverseWord(int begin, int end, string &s) {
        while (begin < end) {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }
};

// O(N) Space Solution 1
class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;

        istringstream iss(s);
        string word;
        while (iss >> word) {
            words.push(word);
        }
        
        string result = "";
        for (; !words.empty(); words.pop()) {
            result += words.top() + " ";
        }
        
        result.pop_back();
        return result;
    }
};

// O(N) Space Solution 2
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string word, result;
        istringstream iss(s);
        
        while (iss >> word) {
            reverse(word.begin(), word.end());
            result += word + " ";
        }
        
        result.pop_back();
        return result;
    }
};
