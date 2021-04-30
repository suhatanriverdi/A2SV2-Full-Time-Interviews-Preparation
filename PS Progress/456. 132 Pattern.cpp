// Question Link: https://leetcode.com/problems/132-pattern

// O(NlogN) Solution Using lower_bound 20ms
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) {
            return false;
        }
        // Find the biggest element smaller than current (32 pattern) in O(N^2) time
        vector<int> nextGreatestSmaller(size, INT_MIN);
        set<int> s;
        set<int>::iterator it;
        for (int i = size - 1; i >= 0; i--) {
            s.insert(nums[i]);
            it = s.lower_bound(nums[i]);
            if (it != s.begin()) {
                it--;
                nextGreatestSmaller[i] = *it;
            }
        }
        // Find if there exists any 32 pattern on my right
        int minSoFar = nums[0];
        for (int i = 0; i < size - 2; i++) {
            minSoFar = min(minSoFar, nums[i]);
            if (minSoFar < nextGreatestSmaller[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

// O(N^2) + O(N) Solution 792ms
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) {
            return false;
        }
        // Find the biggest element smaller than current (32 pattern) in O(N^2) time
        vector<int> nextGreatestSmaller(size, INT_MIN);
        for (int i = 0; i < size; i++) {
            int upperBound = nums[i], maxElem = INT_MIN;
            for (int j = i + 1; j < size; j++) {
                if (nums[j] < upperBound && nums[j] > maxElem) {
                    maxElem = nums[j];
                    nextGreatestSmaller[i] = maxElem;
                }
            }
        }
        // Find if there exists any 32 pattern on my right
        int minSoFar = nums[0];
        for (int i = 0; i < size - 2; i++) {
            minSoFar = min(minSoFar, nums[i]);
            if (minSoFar < nextGreatestSmaller[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

// 2*O(N^2) Solution by checking 32 pattern 1624ms
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) {
            return false;
        }
        // Find the biggest element smaller than current (32 pattern) in O(N^2) time
        vector<int> nextGreatestSmaller(size, INT_MIN);
        for (int i = 0; i < size; i++) {
            int upperBound = nums[i], maxElem = INT_MIN;
            for (int j = i + 1; j < size; j++) {
                if (nums[j] < upperBound && nums[j] > maxElem) {
                    maxElem = nums[j];
                    nextGreatestSmaller[i] = maxElem;
                }
            }
        }
        // Find if there exists any 32 pattern on my right in O(N^2) time
        for (int i = 0; i < size - 2; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] < nextGreatestSmaller[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};