// Question Link: https://leetcode.com/problems/h-index-ii/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size(), l = 0, r = size - 1, mid;
        // We are looking for: max{ F(i) >= i }
        if (size == 0 || citations.back() == 0) {
            return 0;
        }
        while (l < r) {
            mid = (l + r) / 2;
            if (citations[mid] >= (size - mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return size - r;
    }
};