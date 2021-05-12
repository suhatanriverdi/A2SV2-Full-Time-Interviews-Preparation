// Question Link: https://leetcode.com/problems/split-two-strings-to-make-palindrome

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int l = 0, r = a.size() - 1;
        // Check if strings themselves are palindrome
        bool isAPalindrome = isPalindrome(a, a, l, r);
        bool isBPalindrome = isPalindrome(b, b, l, r);
        if (isAPalindrome || isBPalindrome) {
            return true;
        }
        // Check possible match for preA + sufB
        if (a[l] == b[r] && twoPointers(a, b, l, r)) {
            return true;
        }
        // Check possible match for preB + sufA
        if (a[r] == b[l] && twoPointers(b, a, l, r)) {
            return true;
        }
        return false;
    }
    
    bool twoPointers(string &a, string &b, int l, int r) {
        // Continue as long as palindrome condition is being satisfied
        while (l < r && (a[l] == b[r])) {
            l++;
            r--;
        }
        if (l >= r) {
            return true;
        }
        // Swap pointers only once and check rest
        bool swap1 = false, swap2 = false;
        if (a[l] == a[r]) {
            swap1 = isPalindrome(a, a, l, r);
        }
        if (b[l] == b[r]) {
            swap2 = isPalindrome(b, b, l, r);
        }
        return (swap1 || swap2);
    }
    
    bool isPalindrome(string &a, string &b, int l, int r) {
        if (a[l] != b[r]) {
            return false;
        }
        while (l < r && a[l] == b[r]) {
            l++;
            r--;
        }
        return l >= r;
    }
};