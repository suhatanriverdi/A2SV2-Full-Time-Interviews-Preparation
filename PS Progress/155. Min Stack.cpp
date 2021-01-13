// Question Link: https://leetcode.com/problems/min-stack/

class MinStack {
private:
    stack<vector<int>> s;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if (s.empty()) {
            s.push({x, x});
        } else {
            s.push({x, min(x, s.top()[1])});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top()[0];
    }
    
    int getMin() {
        return s.top()[1];
    }
};