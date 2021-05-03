// Question Link: https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        vector<vector<int>> diffCount;
        diffCount.push_back({nums[1] - nums[0], 2});
        for (int i = 2, curDif; i < n; i++) {
            curDif = nums[i] - nums[i - 1];
            if (diffCount.back()[0] == curDif) {
                diffCount.back()[1]++;
            } else {
                diffCount.push_back({curDif, 2});
            }
        }
        int result = 0, k;
        for (int i = 0; i < diffCount.size(); i++) {
            k = diffCount[i][1] - 2;
            result += (k * (k + 1)) / 2;
        }
        return result;
    }
};