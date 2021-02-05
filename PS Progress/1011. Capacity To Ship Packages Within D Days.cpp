// Question Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        // Get possible max and min capacity in O(N)
        int mi = *max_element(begin(weights), end(weights));
        int ma = accumulate(begin(weights), end(weights), 0), currentCapacity, leastWeightCapacity = -1;
        // Binary search on min and max capacity
        while (mi < ma) {
            currentCapacity = (mi + ma) / 2;
            if (possible(weights, D, currentCapacity)) {
                ma = currentCapacity;
            } else {
                mi = currentCapacity + 1;
            }
        }
        return leastWeightCapacity = ma;
    }
    
    // Returns true if we can do the task with C capacity within D days
    bool possible(vector<int> &weights, int D, int cap) {
        int capacity = cap, curDay = 0, i = 0, size = weights.size();
        while (i < size) {
            while (i < size && capacity >= weights[i]) {
                capacity -= weights[i++];
            }
            curDay++; // Increase day
            capacity = cap; // Reset Capacity for next day
            if (curDay > D) {
                return false;
            }
        }
        return (curDay <= D);
    }
};
