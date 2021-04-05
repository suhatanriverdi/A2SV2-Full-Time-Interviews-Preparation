// Question Link: https://leetcode.com/problems/perfect-number/

// Accepted Best Solution O(Sqrt(N)) (0 ms)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        // An odd number cannot be a perfect number
        if (num % 2 == 1) {
            return false;
        }
        // Optimization here!
        // Since we cover all the divisors in this range
        // It is enough to check only the divisors until sqrt(num)
        int sum = 1;
        for (int divisor = 2; divisor <= sqrt(num); divisor++) {
            if (num % divisor == 0) {
                sum += divisor;
                sum += num / divisor;
            }
            if (sum > num) {
                return false;
            }
        }
        return sum == num;
    }
};

// Accepted Better Solution O(N/2) (28 ms)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        // // An odd number cannot be a perfect number
        if (num % 2 == 1) {
            return false;
        }
        // Optimization here!
        // It is enough to check only the evenly divisors
        // for 28 we will have 2 and 14, then 4 and 7
        int sum = 1;
        for (int divisor = 2; divisor <= num / 2; divisor++) {
            int dividend = num / divisor;
            // then 7 and 4, We don't need to go on after divisor > dividend
            // Since we already covered these divisors before
            if (num % divisor == 0) {
                if (divisor > dividend) {
                    break;
                }
                sum += dividend;
                sum += divisor;
            }
            if (sum > num) {
                return false;
            }
        }
        return sum == num;
    }
};

// Accepted Better Solution O(N/2) (652 ms)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        // // An odd number cannot be a perfect number
        if (num % 2 == 1) {
            return false;
        }
        // We did an optimization here!
        // It is enough to check until the half of the number
        // To find all its divisors 28 -> 1,2,4,7,"14"
        // Divisors cannot exceed the half of the number!
        // 14 * 2 = 24, 15 * 2 = 30!
        int sum = 0;
        for (int divisor = 1; divisor <= num / 2; divisor++) {
            if (num % divisor == 0) {
                sum += divisor;
            }
            if (sum > num) {
                return false;
            }
        }
        return sum == num;
    }
};

// Accepted, Optimized Brute Force Solution O(N) (1180 ms)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        // An odd number cannot be a perfect number
        if (num % 2 == 1) {
            return false;
        }
        int divisor = 1, sum = 0;
        for (; divisor != num; divisor++) {
            if (num % divisor == 0) {
                sum += divisor;
            }
            // We did an optimization here!
            // We realized that we don't need to check till the number
            // If  we exceed the sum, there is no reason to continue
            if (sum > num) {
                return false;
            }
        }
        return sum == num;
    }
};

// Brute Force Solution O(N) (Got TLE :)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int divisor = 1, sum = 0;
        for (; divisor != num; divisor++) {
            if (num % divisor == 0) {
                sum += divisor;
            }
        }
        return sum == num;
    }
};