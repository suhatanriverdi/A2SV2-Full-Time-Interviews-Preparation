// Question Link: https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int> maxHeap;
    void addNum(int num) {
        minHeap.push(num);
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
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
};