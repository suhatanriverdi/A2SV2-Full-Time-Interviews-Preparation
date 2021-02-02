// Question Link: https://www.hackerrank.com/challenges/find-the-running-median/

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void add(int n) {
    minHeap.push(n);
    if (minHeap.size() - maxHeap.size() == 2) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
    if (maxHeap.size() > 0 && minHeap.size() > 0 && minHeap.top() < maxHeap.top()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
}

double findMedian() {
    if (minHeap.size() == maxHeap.size()) { 
        return ((minHeap.top() + maxHeap.top()) / (double) 2);
    }
    return minHeap.top();
}

vector<double> runningMedian(vector<int> a) {
    vector<double> result;
    for (int &n : a) {
        add(n);
        result.push_back(findMedian());
    }
    return result;
}