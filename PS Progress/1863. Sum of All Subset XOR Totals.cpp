// Question Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/

// O(2^N)
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return allSubs(0, nums, 0);
    }
    
    int allSubs(int cur, vector<int>& nums, int xoR) {
        if (cur == nums.size()) {
            return xoR;
        }
        // Include
        int include = allSubs(cur + 1, nums, nums[cur] ^ xoR);
        // Exclude
        int exclude = allSubs(cur + 1, nums, xoR);
        return include + exclude;
    }
};

// The Worst Brute Force Solution, O(2^N * N)
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> set;
        int answer = 0;
        allSubs(0, nums, set, answer);
        return answer;
    }
    
    int allSubs(int cur, vector<int>& nums, vector<int> set, int &answer) {
        if (cur == nums.size()) {
            if (set.size() > 0) {
                int sum = set[0];
                for (int i = 1; i < set.size(); i++) {
                    sum ^= set[i];
                }
                answer += sum;
            }
            return 0;
        }
        // Include
        set.push_back(nums[cur]);
        allSubs(cur + 1, nums, set, answer);
        // Exclude
        set.pop_back();
        allSubs(cur + 1, nums, set, answer);
        return 0;
    }
};