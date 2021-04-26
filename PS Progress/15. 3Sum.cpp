// Question Link: https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> result;
        if (N < 2) {
            result;
        }
        set<vector<int>> seen;
        sort(begin(nums), end(nums));
        for (int i = 0; i < N - 2; i++) {
            int j = i + 1;
            int k = N - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    seen.insert({nums[i], nums[j++], nums[k--]});
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        for (auto &answer : seen) {
            result.push_back(answer);
        }
        return result;
    }
};