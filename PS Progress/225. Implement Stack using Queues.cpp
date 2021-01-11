// Question Link: https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i = q.size() - 1; i > 0; i--) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int returnVal = q.front();
        q.pop();
        return returnVal;
    }
    
    /** Get the top element. */
    int top() {
        return  q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};