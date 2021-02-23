// Question Link: https://www.hackerrank.com/challenges/poisonous-plants/problem

int poisonousPlants(vector<int> p) {
    stack<vector<int>> plantDayStack; // {plant, death day}
    plantDayStack.push({p[0], 0});
    int result = 0, lastAlive = p[0];
    for (int i = 1; i < p.size(); i++) {
        // Definite poisy plant
        if (p[i] > p[i - 1]) {
            plantDayStack.push({p[i], 1});
        }
        // Possible poisy plant
        else {
            // Update last alive plant
            if (p[i] <= lastAlive) {
                lastAlive = p[i];
                plantDayStack.push({p[i], 0});
            }
            // Definite poisy plant
            else {                
                int maxDay = 0;
                while (!plantDayStack.empty() && p[i] <= plantDayStack.top()[0]) {
                    maxDay = max(maxDay, plantDayStack.top()[1]);
                    plantDayStack.pop();
                }
                plantDayStack.push({p[i], (maxDay == 0 ? 0 : maxDay + 1)});
                result = max(result, plantDayStack.top()[1]);
            }       
        }
        result = max(result, plantDayStack.top()[1]);
    }
    return result;
}