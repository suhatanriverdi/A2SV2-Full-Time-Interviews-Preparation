// Question Link: https://leetcode.com/problems/tuple-with-same-product/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) {
            return 0;
        }
        int result = 0;
        unordered_map<long long int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long int prod = nums[i] * nums[j];
                map[prod]++;
            }   
        }
        for (auto &it : map) {
            if (it.second > 1) {
                if (it.second == 2) {
                    result += 8;
                } else {
                    int n = it.second;
                    result += ((n * (n - 1)) / 2) * 8;
                }
            }
        }
        return result;
    }
};