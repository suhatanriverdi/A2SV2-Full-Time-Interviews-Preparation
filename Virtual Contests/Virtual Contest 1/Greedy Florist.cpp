// Question Link: https://www.hackerrank.com/challenges/greedy-florist/problem

int getMinimumCost(int k, vector<int> c) {
    sort(begin(c), end(c), greater<int>());
    int minCost = 0;
    auto comp = [](vector<int> &a, vector<int> &b) {
        if (a[0] > b[0]) {
            return true;
        }
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return false;
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> friendsPQ(comp);
    while (k--) {
        friendsPQ.push({0, 0});
    }
    for (int &fCost : c) {
        vector<int> cur = friendsPQ.top();
        friendsPQ.pop();
        // increment previous purchases
        cur[0]++;
        // Update new cost sum
        cur[1] = cur[0] * fCost;
        // Calculate total min cost
        minCost += cur[1];
        // Re-push to PQ
        friendsPQ.push(cur);
    }
    return minCost;
}