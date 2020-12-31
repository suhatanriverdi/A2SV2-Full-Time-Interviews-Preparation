// Question Link: https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueIndexMap; // {value, index}
        for (int i = 0; i < nums.size(); i++) {
            int remNum = target - nums[i];
            if (valueIndexMap.find(remNum) != valueIndexMap.end()) {
                return {i, valueIndexMap[remNum]};
            }
            valueIndexMap[nums[i]] = i;
        }
        return {};
    }
};