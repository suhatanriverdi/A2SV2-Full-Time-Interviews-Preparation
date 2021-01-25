// Question Link: https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minPQ;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int num : nums) {
            minPQ.push(num);
            if (minPQ.size() > k) {
                minPQ.pop();
            }
        }
    }
    
    int add(int val) {
        minPQ.push(val);
        if (minPQ.size() > K) {
            minPQ.pop();
        }
        return minPQ.top();
    }
};