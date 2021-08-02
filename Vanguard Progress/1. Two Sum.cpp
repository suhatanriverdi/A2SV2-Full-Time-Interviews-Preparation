// Question Link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // a + b = target
        // target - b = a
        // We will check if we have a in the map
        unordered_map<int, int> idxValMap; // { value, index }
        vector<int> result = { 0, 1 };
        for (int i = 0; i < nums.size(); i++) {
            int wanted = target - nums[i];
            if (idxValMap.find(wanted) != idxValMap.end()) {
                result = { idxValMap[wanted], i };
                break;
            }
            idxValMap[nums[i]] = i;
        }
        return result;
    }
};