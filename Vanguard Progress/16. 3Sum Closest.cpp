// Question Link: https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        /*
            [-5,-4,-3,-2,3]
              ^  ^       ^
              a  b       c
            
            a + b + c =~ target
            
            ! since this 'ideal' pair may not exist
            ! We'll be looking for the smallest absolute difference of (target - v)
        */
        int diff, prevDiff = INT_MAX;
        int sum, answer;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            // Two pointers
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                diff = abs(target - sum);
                if (diff < prevDiff) {
                    prevDiff = diff;
                    answer = sum;
                }
                if (sum == target) {
                    return sum;
                }
                if (sum < target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return answer;
    }
};