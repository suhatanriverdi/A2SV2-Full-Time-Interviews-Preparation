// Question Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

// Set Solution
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int longestFibSubseqLen = 0, n = arr.size();
        unordered_set<int> set(begin(arr), end(arr));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = arr[i];
                int y = arr[j];
                int sum = x + y;
                int localLen = 2;
                while (set.find(sum) != set.end()) {
                    x = y;
                    y = sum;
                    sum = x + y;
                    localLen++;
                }
                longestFibSubseqLen = max(localLen, longestFibSubseqLen);
            }   
        }
        return (longestFibSubseqLen < 3 ? 0 : longestFibSubseqLen);
    }
};

// Map Solution
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int longestFibSubseqLen = 0, n = arr.size();
        unordered_map<int, int> map;
        for (int &n : arr) {
            map[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = arr[i];
                int y = arr[j];
                int sum = x + y;
                int localLen = 2;
                while (map.find(sum) != map.end()) {
                    x = y;
                    y = sum;
                    sum = x + y;
                    localLen++;
                }
                longestFibSubseqLen = max(localLen, longestFibSubseqLen);
            }   
        }
        return (longestFibSubseqLen < 3 ? 0 : longestFibSubseqLen);
    }
};