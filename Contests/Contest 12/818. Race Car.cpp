// Question Link: https://leetcode.com/problems/race-car/

class Solution {
public:
    int racecar(int target) {
        set<vector<int>> seen;
        queue<vector<int>> todo;
        todo.push({0, 1, 0}); // {pos, speed, steps}
        seen.insert({0, 1});
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            int pos = cur[0];
            int speed = cur[1];
            int steps = cur[2];
            // If our position is target
            if (pos == target) {
                return steps;
            }
            // Try A
            if ((pos + speed <= 10000 && pos + speed > 0) && seen.find({pos + speed, speed * 2}) == seen.end()) {
                todo.push({pos + speed, speed * 2, steps + 1});
                seen.insert({pos + speed, speed * 2});
            }
            // Try R
            int newSpeedR = (speed > 0 ? -1 : 1);
            if (seen.find({pos, newSpeedR}) == seen.end()) {
                todo.push({pos, newSpeedR, steps + 1});
                seen.insert({pos, newSpeedR});
            }
        }
        return -1;
    }
};
