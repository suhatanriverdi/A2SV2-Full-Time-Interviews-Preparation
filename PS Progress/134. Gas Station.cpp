// Question Link: https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, size = gas.size(), answer = INT_MAX, curGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            curGas += gas[i] - cost[i];
            // Possible answer
            if (curGas >= 0) {
                answer = min(answer, i);
            }
            // Reset
            else {
                answer = INT_MAX;
                curGas = 0;
            }
            sum += gas[i] - cost[i];
        }
        return (sum < 0) ? -1 : answer;
    }
};
