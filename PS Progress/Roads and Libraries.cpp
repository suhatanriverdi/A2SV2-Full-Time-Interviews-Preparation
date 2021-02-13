// Question Link: https://leetcode.com/problems/jump-game-iii/

// DFS Solution
// To find how many different independent cities in the graph
void dfs(int cur, vector<vector<int>> &adjList, unordered_set<int> &seen, int &numOfCities) {
    for (int &node : adjList[cur]) {
        // If not visited
        if (seen.find(node) == seen.end()) {
            seen.insert(node);
            numOfCities++;
            dfs(node, adjList, seen, numOfCities);
        }
    }
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    vector<vector<int>> adjList(n + 1, vector<int>());
    // Build graph
    for (vector<int> &city : cities) {
        adjList[city[0]].push_back(city[1]);
        adjList[city[1]].push_back(city[0]);
    }
    // To check cisited node
    unordered_set<int> seen;
    int tmpCitiesCount = 0;
    vector<int> numOfCities;
    for (int i = 1; i < adjList.size(); i++) {
        if (seen.find(i) == seen.end()) {
            tmpCitiesCount = 1;
            seen.insert(i);
            dfs(i, adjList, seen, tmpCitiesCount);
            numOfCities.push_back(tmpCitiesCount);
        }
    }
    long long int result = 0, totalLibCost, totalRoadCost, roadsAndOneLib;
    for (int &curCityN : numOfCities) {
        // If lib to everywhere cost
        totalLibCost = curCityN * c_lib;
        totalRoadCost = (curCityN - 1) * c_road;
        roadsAndOneLib = totalRoadCost + c_lib;
        if (totalLibCost <= roadsAndOneLib) {
            result += totalLibCost;
        } else {
            result += roadsAndOneLib;
        }
    }
    return result;
}