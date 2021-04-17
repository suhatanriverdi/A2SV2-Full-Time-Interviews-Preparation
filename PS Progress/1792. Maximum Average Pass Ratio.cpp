// Question Link: https://leetcode.com/problems/maximum-average-pass-ratio

struct info {
    int pass = 0;
    int total = 0;
    double incRatio = 0.0;
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Compare classes with respect to thier increase ratios, the greater increase ratio comes first
        auto comp = [](info &a, info &b){
            if (a.incRatio < b.incRatio) {
                return true;
            }
            return false;
        };
        priority_queue<info, vector<info>, decltype(comp)> passRatioPQ(comp);
        double passRatio, passRatioWithExtra, increaseRatio, oldPassRatio, newPassRatio, futureIncRatio, avgPassRatio = 0.0;
        for (vector<int> &c : classes) {
            // Calculate original pass ratio
            passRatio = 1.0 * c[0] / c[1];
            // Calculate "increase ratio" after we add 1 extra student
            passRatioWithExtra = 1.0 * (c[0] + 1) / (c[1] + 1);
            increaseRatio = passRatioWithExtra - passRatio;
            passRatioPQ.push({c[0], c[1], increaseRatio});
            avgPassRatio += passRatio;
        }
        // Add extra students to the class whose increase ratio is max at top of PQ
        while (extraStudents--) {
            info cur = passRatioPQ.top();
            passRatioPQ.pop();
            // Substract the old pass ratio from average pass ratio
            oldPassRatio = 1.0 * cur.pass / cur.total;
            avgPassRatio -= oldPassRatio;
            // Calculate new pass ratio
            cur.pass += 1;
            cur.total += 1;
            newPassRatio = 1.0 * cur.pass / cur.total;
            // Add new pass ratio to average pass ratio
            avgPassRatio += newPassRatio;
            // Update increase ratio and push it to the PQ
            futureIncRatio = 1.0 * (cur.pass + 1) / (cur.total + 1);
            cur.incRatio = futureIncRatio - newPassRatio;
            passRatioPQ.push({cur.pass, cur.total, cur.incRatio});
        }
        avgPassRatio = 1.0 * avgPassRatio / classes.size();
        return avgPassRatio;
    }
};