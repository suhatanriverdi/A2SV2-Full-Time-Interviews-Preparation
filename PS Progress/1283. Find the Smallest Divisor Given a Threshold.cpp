// Question Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(begin(nums), end(nums)), mid, currentDivSum = 0;
        while (l < r) {
            mid = (l + r) / 2;
            currentDivSum = divSum(nums, mid);
            if (currentDivSum <= threshold) {
                r = mid;
            }
            else if (currentDivSum > threshold) {
                l = mid + 1;
            }
        }
        return l;
    }
    
    int divSum(vector<int> &nums, int &divisor) {
        int sum = 0, tmp;
        for (int &num : nums) {
            tmp = (num / divisor);
            sum += (tmp == 0 ? 1 : (tmp + ((num % divisor) >= 1 ? 1 : 0)));
        }
        return sum;
    }
};