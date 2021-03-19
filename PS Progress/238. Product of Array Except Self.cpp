// Question Link: https://leetcode.com/problems/product-of-array-except-self/

// O(N) Without Using Division
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> L(N, 1), R(N, 1), result(N);
        // Get the Right Product
        for (int i = N - 2; i >= 0; i--) {
            R[i] *= R[i + 1] * nums[i + 1];
        }
        // Get the Left Product
        for (int i = 1; i < N; i++) {
            L[i] *= L[i - 1] * nums[i - 1];
        }
        // Fill the result array
        for (int i = 0; i < N; i++) {
            result[i] = L[i] * R[i];
        }
        return result;
    }
};

// O(N) By Using division "/"
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zerosCnt = 0, zeroIndices;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroIndices = i;
                zerosCnt++;
            }
        }
        vector<int> result(nums.size(), 0);
        if (zerosCnt > 1) {
            return result;
        }
        // If we have a zero
        int sumProd = 1;
        for (int i = 0; i < nums.size(); i++) {
            // Except that one zero, get all product
            if (i != zeroIndices) {
                sumProd *= nums[i]; 
            }
        }
        if (zerosCnt == 1) {
            result[zeroIndices] = sumProd;
        } 
        else {
            sumProd *= nums[zeroIndices]; // We know there is no zero, add zeroIndex to to sumProd as well
            result[zeroIndices] = sumProd;
            // Find individual prod on result
            for (int i = 0; i < result.size(); i++) {
                result[i] = sumProd / nums[i]; 
            }
        }
        return result;
    }
};
