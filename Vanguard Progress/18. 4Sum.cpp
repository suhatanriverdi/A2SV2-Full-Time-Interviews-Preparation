// Question https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int N = nums.size();
        if (N < 4) {
            return result;
        }
        sort(begin(nums), end(nums));
        int i = 0;
        while (i < N - 3) {
            int j = i + 1;
            while (j < N - 2) {
                int k = j + 1;
                while (k < N - 1) {
                    long long int sum3 = nums[i];
                    sum3 += nums[j];
                    sum3 += nums[k];
                    long long int find = target - sum3;
                    if (binary_search(nums.begin() + k + 1, nums.end(), find)) {
                        result.push_back({ nums[i], nums[j], nums[k], (int)find });
                    }
                    k++;
                    incrementor(k, N - 1, N, nums);
                }
                j++;
                incrementor(j, N - 2, N, nums);
            }
            i++;
            incrementor(i, N - 3, N, nums);
        }
        return result;
    }
    
    void incrementor(int &index, int upperBound, int &N, vector<int> &nums) {
        for (; index < upperBound && nums[index] == nums[index - 1]; index++) {
            
        }
    }
};