// Question Link: https://leetcode.com/problems/fruit-into-baskets/

// C++ Two Pointers O(N) Solution
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> basketsMap;
        int len = tree.size();
        int result = 0, count = 0;
        int L = 0;
        for (int R = 0; R < len; R++) {
            // Add current fruit into baskets
            basketsMap[tree[R]]++;
            count++;
            // If we have 3 types of fruits, remove some from left
            while (basketsMap.size() >= 3) {
                basketsMap[tree[L]]--;
                count--;
                if (basketsMap[tree[L]] == 0) {
                    basketsMap.erase(tree[L]);
                }
                L++;
            }
            result = max(result, count);
        }
        return result;
    }
};

// The following was my initial code, I optimized it like above
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int len = tree.size(), numOfFruits = 0, result = 1;
        unordered_map<int, int> basketsMap = { { tree[0], 1 } };
        int R = 1;
        int firstSeenIndex = 1; // The beginning of the second type fruit
        while (R < len) {
            // If number of types is less than or equal to 2
            while ((R < len) && (basketsMap.size() <= 1 || basketsMap.find(tree[R]) != basketsMap.end())) {
                basketsMap[tree[R]]++;
                if (basketsMap.size() == 2) {
                    firstSeenIndex = min(firstSeenIndex, R);
                }
                R++;
            }
            // Get total number of types from map
            numOfFruits = getNumOfFruits(basketsMap);
            result = max(result, numOfFruits);
            
            // Edge case
            if (R >= len) {
                return result;
            }
            
            // Empty baskets
            basketsMap.clear();
            // Start from the begining of the first second type fruit
            R = firstSeenIndex;
            basketsMap[tree[R]]++;
            R++;
            // Update firstSeenIndex
            firstSeenIndex = R;
        }
        //Update result one more time
        numOfFruits = getNumOfFruits(basketsMap);
        result = max(result, numOfFruits);
        return result;
    }
    
    int getNumOfFruits(unordered_map<int, int> basketsMap) {
        int numOfFruits = 0;
        for (auto &it : basketsMap) {
            numOfFruits += it.second;
        }
        return numOfFruits;
    }
};

