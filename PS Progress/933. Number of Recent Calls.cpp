// Question Link: https://leetcode.com/problems/number-of-recent-calls/

class RecentCounter {
private:
    vector<int> requests;
public:
    RecentCounter() {}
    int ping(int t) {
        requests.push_back(t);
        int lastTime = (requests.back() - 3000), count = 0;
        for (int i = requests.size() - 1; i >= 0 && requests[i] >= lastTime; i--) {
            count++;
        }
        return count;
    }
};