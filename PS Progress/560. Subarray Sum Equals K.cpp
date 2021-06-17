// Question Link: https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0, len = nums.size();
        unordered_map<int, int> sumsMap;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            if (sum == k) {
                count++;
            }
            int need = sum - k;
            if (sumsMap.find(need) != sumsMap.end()) {
                count += sumsMap[need];
            }
            sumsMap[sum]++;
        }
        return count;
    }
};