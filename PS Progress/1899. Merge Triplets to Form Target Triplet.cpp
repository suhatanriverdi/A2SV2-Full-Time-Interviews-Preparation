// Question Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        bool hasTarget[3] = { false };
        // Check target[0]
        for (int i = 0; i < n; i++) {
            if (triplets[i][0] == target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                hasTarget[0] = true;
                break;
            }
        }

        // Check target[1]
        for (int i = 0; i < n; i++) {
            if (triplets[i][1] == target[1] && triplets[i][0] <= target[0] && triplets[i][2] <= target[2]) {
                hasTarget[1] = true;
                break;
            }
        }

        // Check target[2]
        for (int i = 0; i < n; i++) {
            if (triplets[i][2] == target[2] && triplets[i][1] <= target[1] && triplets[i][0] <= target[0]) {
                hasTarget[2] = true;
                break;
            }
        }

        return hasTarget[0] && hasTarget[1] && hasTarget[2];
    }
};
