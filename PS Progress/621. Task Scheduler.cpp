// Question Link: https://leetcode.com/problems/task-scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        if (n == 0) {
            return size;
        }
        unordered_map<char, int> tasksCountMap; // { Task, Count }
        for (char task : tasks) {
            tasksCountMap[task]++;
        }
        priority_queue<int> countsPQ; // { taskCounts }
        for (auto it : tasksCountMap) {
            countsPQ.push(it.second);
        }
        int totalTime = 0, tmpTime;
        while (!countsPQ.empty()) {
            vector<int> tmp;
            tmpTime = 0;
            for (int i = 0; i <= n; i++) {
                if (!countsPQ.empty()) {
                    tmp.push_back(countsPQ.top());
                    countsPQ.pop();
                    tmpTime++;
                }
            }
            for (int t : tmp) {
                if (--t > 0) {
                    countsPQ.push(t);
                }
            }
            totalTime += (countsPQ.empty() ? tmpTime : n + 1);
        }
        
        return totalTime;
    }
};