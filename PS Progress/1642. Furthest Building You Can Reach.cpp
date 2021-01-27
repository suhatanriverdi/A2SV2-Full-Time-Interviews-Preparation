// Question Link: https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // To hold longest jumps we have jumped over so far
        priority_queue<int> maxPQ;
        for (int i = 1, dif; i < heights.size(); i++) {
            dif = heights[i] - heights[i - 1];
            // If there is elevation
            if (dif > 0) {
                // Save elevation
                maxPQ.push(dif);
                // Keep using bricks as long as we can
                if (bricks >= dif) {
                    bricks -= dif;
                } 
                else {
                    // Exchange ladders with bricks
                    if (maxPQ.size() > 0 && ladders > 0) {
                        // Check before exchange if it is enough to jump over current building
                        if (maxPQ.top() + bricks < dif) {
                            ladders--;
                        } else {
                            bricks += maxPQ.top();
                            maxPQ.pop();
                            ladders--;
                            bricks -= dif;
                        }
                    }
                    // If we cannot use bricks and exchange, use ladders if we have instead
                    else if (ladders > 0) {
                        ladders--;
                    }
                    else {
                        return i - 1;
                    }
                }
            }
        }
        return heights.size() - 1;
    }
};