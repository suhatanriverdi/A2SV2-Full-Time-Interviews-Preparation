// Question Link: https://leetcode.com/problems/3sum

// 336ms Without Using Set
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> result;
        if (N < 2) {
            result;
        }
        sort(begin(nums), end(nums));
        for (int i = 0; i < N - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            int k = N - 1;
            while (i < k - 1) {
                int find = -(nums[i] + nums[k]);
                if (binary_search(nums.begin() + i + 1, nums.begin() + k, find)) {
                    result.push_back({nums[i], find, nums[k]});
                }
                k--;
                while (i < k - 1 && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
            while (i < N - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return result;
    }
};

// 1100ms Using Set
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
            if (nums[i] > 0) {
                break;
            }
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
