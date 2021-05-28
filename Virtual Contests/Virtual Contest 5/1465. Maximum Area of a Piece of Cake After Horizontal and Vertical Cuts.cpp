// Question Link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        hCuts.push_back(h);
        vCuts.push_back(w);
        sort(begin(hCuts), end(hCuts));
        sort(begin(vCuts), end(vCuts));
        // Calculate Horizontal Max Length
        long long int start = 0;
        long long int end = hCuts[0], endIndex = 0;
        long long int maxHoriLen = 0;
        while (endIndex < hCuts.size()) {
            maxHoriLen = max(maxHoriLen, (end - start));
            // Update Start
            start = hCuts[endIndex];
            endIndex++;
            if (endIndex < hCuts.size()) {
                end = hCuts[endIndex];
            }
        }
        // Calculate Vertical Max Length
        start = 0;
        end = vCuts[0], endIndex = 0;
        long long int maxVertiLen = 0;
        while (endIndex < vCuts.size()) {
            maxVertiLen = max(maxVertiLen, (end - start));
            // Update Start
            start = vCuts[endIndex];
            endIndex++;
            if (endIndex < vCuts.size()) {
                end = vCuts[endIndex];
            }
        }
        long long int mul = (maxHoriLen * maxVertiLen);
        return (mul) % 1000000007;
    }
};