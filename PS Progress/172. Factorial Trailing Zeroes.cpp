// Question Link: https://leetcode.com/problems/factorial-trailing-zeroes/

// O(log(N)) Shorter Solution
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        // We just need to find how many 5's we have in n
        while (n > 0) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};

// O(N) Solution
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        // Since we have enought 2's because of even numbers
        // It is enough to count only 5's
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0) {
                // Check for power of 5
                int pow5 = i;
                while ((pow5 % 5) == 0) {
                    pow5 /= 5;
                    count++;
                }
            }
        }
        return count;
    }
};