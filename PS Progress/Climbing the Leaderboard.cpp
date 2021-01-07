// Question Link: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

int binarySearch(vector<vector<int>> &ranks, int &ranksSize, int &pointToSearch) {
    int left = 0, right = ranksSize - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (pointToSearch == ranks[mid][0]) {
            return mid;
        }
        else if (pointToSearch > ranks[mid][0]) {
            right = mid - 1; // Array is descending order
        } else {
            left = mid + 1;
        }
    }
    return mid;
}

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    int prevPoint = ranked[0], rankedSize = ranked.size(), curRank = 1;
    vector<vector<int>> ranks = {{ranked[0], curRank++}}; // {point, rank}
    for (int i = 1; i < rankedSize; i++) {
        if (ranked[i] != prevPoint) {
            ranks.push_back({ranked[i], curRank++}); // {point, rank}
            prevPoint = ranked[i];
        }
    }
    int ranksSize = ranks.size(), rankPointIndex;
    vector<int> result;
    for (int point : player) {
        rankPointIndex = binarySearch(ranks, ranksSize, point);
        if (point >= ranks[rankPointIndex][0]) {
            result.push_back(ranks[rankPointIndex][1]);
        } else {
            result.push_back(ranks[rankPointIndex][1] + 1);
        }
    }
    return result;
}

