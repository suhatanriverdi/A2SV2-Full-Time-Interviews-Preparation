// Question Link: https://leetcode.com/problems/car-fleet/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int carFleetsCount = 0, size = position.size();
        if (size == 0) {
            return carFleetsCount;
        }
        map<int, pair<int, double>> posSpeedArrivalMap; // {pos in ascending order, {speed, arrival time}}
        for (int i = 0; i < size; i++) {
            posSpeedArrivalMap[position[i]] = {speed[i], (target - position[i]) / (double)speed[i]};
        }
        bool hasCarFleet = carFleetPossible(posSpeedArrivalMap);
        while (hasCarFleet) {
            hasCarFleet = carFleetPossible(posSpeedArrivalMap);
        }
        carFleetsCount = posSpeedArrivalMap.size();
        return carFleetsCount;
    }
    
    // Try to make car fleets and return true if we could make it
    bool carFleetPossible(map<int, pair<int, double>> &posSpeedArrivalMap) {
        auto prev = posSpeedArrivalMap.begin(), end = posSpeedArrivalMap.end();
        auto next = posSpeedArrivalMap.begin();
        next++;
        while (prev != end) {
            if ((next != end) && prev->second.second <= next->second.second) {
                // Remove the faster one behind, since they will become car fleet
                posSpeedArrivalMap.erase(prev);
                return true;                
            }
            prev++;
            next++;
        }
        return false;
    }
};