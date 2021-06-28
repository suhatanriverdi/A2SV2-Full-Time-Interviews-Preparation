// Question Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int len = nums.size();
        long sum = 0, answer = len + 1, wanted;
        map<long, long> map;
        for (long i = 0; i < nums.size(); i++) {
            // Update running sum
            sum += nums[i];
            // Check single values
            if (nums[i] >= k) {
                return 1;
            }
            // Check prefix sum
            if (sum >= k) {
                answer = min(answer, i + 1);
            }
            // P[X] <= P[Y] - K  --->  where P[X] is "wanted", we are looking for it
            wanted = sum - k;
            auto until = map.upper_bound(wanted);
            for (auto it = map.begin(); it != until; it++) {
                answer = min(answer, i - (it->second));
            }
            // Remove all P[x] sums we won't need anymore
            map.erase(map.begin(), until);
            // Store each prefix sum seen so far
            map[sum] = i;
        }
        return answer == len + 1 ? -1 : answer;
    }
};