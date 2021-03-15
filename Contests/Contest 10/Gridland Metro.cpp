// Question Link: https://www.hackerrank.com/challenges/gridland-metro/problem

// Check if two intervals overlap if so updates and returs new merged interval
vector<int> doesOverlap(int &a, int &b, int &c, int &d) {
    if ((a <= c && c <= b) || (a <= d && d <= b) ||
        (c <= a && a <= d) || (c <= b && b <= d)) {
        int newLeft = min(a, c);
        int newRight = max(b, d);
        return { newLeft, newRight };
    }
    return { -1 };
}

// Complete the gridlandMetro function below.
long long int gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
    unordered_map<int, vector<vector<int>>> overlapMap;
    // Save all overlapping & unoverlapping intervals
    for (vector<int> &row : track) {
        overlapMap[row[0]].push_back({row[1], row[2]});
    }
    // Update all overlapping intervals
    long long int totalFreeCells = (long long int)n * m, trainWaySum = 0;
    for (auto &t : overlapMap) {
        stack<vector<int>> updatedIntervals;
        // First sort the intervals to merge them easily
        sort(begin(t.second), end(t.second));
        // Merge sorted intervals
        updatedIntervals.push(t.second[0]);
        for (int cur = 1; cur < t.second.size(); cur++) {
            int a = updatedIntervals.top()[0], b = updatedIntervals.top()[1];
            int c = t.second[cur][0], d = t.second[cur][1];
            vector<int> newMergedInterval = doesOverlap(a, b, c, d);
            // If merging succesful
            if (newMergedInterval[0] != -1) {
                updatedIntervals.pop();
                updatedIntervals.push(newMergedInterval);
            }
            else {
                updatedIntervals.push({c, d});
            }
        }
        // Calculate total train way for current row
        while (!updatedIntervals.empty()) {
            vector<int> row = updatedIntervals.top();
            updatedIntervals.pop();
            trainWaySum += (row[1] - row[0] + 1);
        }
    }
    return totalFreeCells - trainWaySum;
}
