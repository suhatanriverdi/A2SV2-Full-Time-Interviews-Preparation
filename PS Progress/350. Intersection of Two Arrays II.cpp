// Question Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Follow-Up 3
// What if elements of nums2 are stored on disk
// and the memory is limited such that you cannot load all elements into the memory at once?
// In that case, we put all elements of nums1 into memory then we can load as many elements from nums2 as possible and do the comparison fragmentedly
// If that is not possible, we can then use External sorting

// Follow-Up 2
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// Since O(1) < O(logn) < O(n) < O(nlogn)
// Initially Solution 1 is better but if nums1 is K size. Then we should do binary search for every element in nums1. Each lookup is 
// O(log N) where N is nums2 size, and since we do K times, we have O(K log N).
// If K this is small enough, O(K log N) < O(max(A, B)).
// Overall time complexity: O(K (log N) + L) where L is for duplicate element search.
// After finding the index we can do linear search to eliminate duplicates on both arrays.
// A = [1,3,3,3,3,3,4]
// B = [3,3] -> We start BS for each element of small sized array

// Follow-Up 1
// What if the given array is already sorted? How would you optimize your algorithm?
// Time: O(max(ALogA + BLogB) + max(A + B)) where A is length of nums1 and B is ength of nums2
// Space: O(N) where N is the number of intersecting elements
class Solution {
public:
    vector<int> intersect(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A)); // AlogA
        sort(begin(B), end(B)); // BlogB
        vector<int> result;
        // Two pointers
        int a = 0, b = 0;
        // worst case A = [1,2,3,5]
        //            B = [4,4,4,4]
        while (a < A.size() && b < B.size()) { // O(A) + O(B)
            if (A[a] == B[b]) {
                result.push_back(A[a]);
                a++;
                b++;
            }
            else if (A[a] < B[b]) {
                a++;
            }
            else {
                b++;
            }
        }
        return result;
    }
};

// Initial Solution
// Time: O(A) + O(B) where A is length of nums1 and B is ength of nums2
// Space: O(N) where N is the number of intersecting elements
class Solution {
public:
    vector<int> intersect(vector<int>& A, vector<int>& B) {
        vector<int> result, AMap(1001, 0);
        for (int &a : A) { // O(A)
            AMap[a]++;
        }
        for (int &b : B) { // O(B)
            if (AMap[b] > 0) {
                result.push_back(b);
                AMap[b]--;
            }
        }
        return result;
    }
};