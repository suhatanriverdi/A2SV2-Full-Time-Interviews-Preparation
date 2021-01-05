// Question Link: https://leetcode.com/problems/relative-sort-array/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> countArray(1001, 0), result;
        for (int n1 : arr1) {
            countArray[n1]++;
        }
        for (int i = 0; i < arr2.size(); i++) {
            while (countArray[arr2[i]] > 0) {
                result.push_back(arr2[i]);
                countArray[arr2[i]]--;
            }
        }
        for (int i = 0; i < countArray.size(); i++) {
            while (countArray[i] > 0) {
                result.push_back(i);
                countArray[i]--;
            }
        }
        return result;
    }
};