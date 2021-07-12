// Question Link: https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        // Send the top element of maxHeap to minHeap 
        if (minHeap.empty() || maxHeap.top() >= minHeap.top() || maxHeap.size() == minHeap.size() + 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // Send the top element of minHeap to maxHeap 
        if (minHeap.size() == maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return 1.0 * (maxHeap.top() + minHeap.top()) / 2;
        }
        return maxHeap.top();
    }
};