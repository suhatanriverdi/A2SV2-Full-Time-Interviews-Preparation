// Question Link: https://leetcode.com/problems/pancake-sorting/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        for (int i = arr.size(); i > 0; i--) {
            vector<int>::iterator curMax = max_element(arr.begin(), arr.begin() + i); // Find current max element
            reverse(arr.begin(), arr.begin() + distance(arr.begin(), curMax) + 1); // reverse subarray till max element
            result.push_back(distance(arr.begin(), curMax) + 1);
            reverse(arr.begin(), arr.begin() + i); // reverse whole array
            result.push_back(i);
        }
        return result;
    }
};
