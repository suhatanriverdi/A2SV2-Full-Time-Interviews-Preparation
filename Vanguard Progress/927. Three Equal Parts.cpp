// Question Link: https://leetcode.com/problems/three-equal-parts/

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int numOf1s = count(begin(arr), end(arr), 1);
        
        // Impossible 1
        if (numOf1s % 3 != 0) {
            return { -1, -1 };
        }
        
        // All zero
        if (numOf1s == 0) {
            return { 0, 2 };
        }
        
        int amount = numOf1s / 3;
        int len = arr.size();
        
        vector<int> first = findStartEnd(amount, 0, len, arr);
        vector<int> second = findStartEnd(amount, first[1] + 1, len, arr);
        vector<int> third = findStartEnd(amount, second[1] + 1, len, arr);
        int numOfTrailingZeros = len - third[1] - 1;
        third[1] = len - 1; // tailing zero

        int idxA = first[0];
        int idxB = second[0];
        int idxC = third[0];
        while (idxC < len) {
            if (arr[idxA] != arr[idxB] || arr[idxB] != arr[idxC]) {
                return {-1, -1};    
            }
            idxA++;
            idxB++;
            idxC++;
        }
        
        return { first[1] + numOfTrailingZeros, second[1] + 1 + numOfTrailingZeros };
    }
    
    int getIntervalLen(vector<int> &interval) {
        return interval[1] - interval[0] + 1;
    }

    vector<int> findStartEnd(int amount, int begin, int &len, vector<int> &arr) {
        int start = INT_MAX;
        int end = INT_MIN;
        for (int i = begin; i < len && amount > 0; i++) {
            if (arr[i] == 1) {
                start = min(start, i);
                end = max(end, i);
                amount--;
            }
        }
        return { start, end };
    }
};
