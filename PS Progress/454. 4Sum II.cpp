// Question Link: https://leetcode.com/problems/4sum-ii/

// N^2 Solution
class Solution {
public:
    int fourSumCount(vector<int>& n1, vector<int>& n2, vector<int>& n3, vector<int>& n4) {
        unordered_map<int, int> Amap, Bmap;
        vector<vector<int>> listA = { n1, n2 }, listB = { n3, n4 };
        int result = 0, sum = 0;
        helper(sum, 0, listA, Amap);
        helper(sum, 0, listB, Bmap);
        for (auto &a : Amap) {
            for (auto &b : Bmap) {
                if (a.first + b.first == 0) {
                    result += a.second * b.second;
                }
            }
        }
        return result;
    }
    
    void helper(int sum, int curList, vector<vector<int>> &lists, unordered_map<int, int> &sumCountMap) {
        if (curList == 2) {
            sumCountMap[sum]++;
            return;
        }
        for (int &n : lists[curList]) {
            helper(sum + n, curList + 1, lists, sumCountMap);
        }
    }
};

// N^4 TLE Solution
// Brute Force GOT TLE O(N^4)
class Solution {
public:
    int fourSumCount(vector<int>& n1, vector<int>& n2, vector<int>& n3, vector<int>& n4) {
        vector<vector<int>> lists = { n1, n2, n3, n4 };
        int sum = 0;
        return helper(sum, 0, lists);
    }
    
    int helper(int sum, int curList, vector<vector<int>> &lists) {
        if (curList == 4) {
            return (sum == 0) ? 1 : 0;
        }
        int result = 0;
        for (int &n : lists[curList]) {
            result += helper(sum + n, curList + 1, lists);
        }
        return result;
    }
};