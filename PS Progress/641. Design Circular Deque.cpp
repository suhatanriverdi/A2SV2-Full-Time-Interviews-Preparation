// Question Link: https://leetcode.com/problems/design-circular-deque

class MyCircularDeque {
    vector<int> front, rear;
    int size, capacity;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
        capacity = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front.push_back(value);
        size--;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        rear.push_back(value);
        size--;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        if (front.empty()) {
            if (rear.size() > 0) {
                rear.erase(rear.begin());
                size++;
                return true;
            } else {
                return false;
            }
        } 
        front.pop_back();
        size++;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        if (rear.empty()) {
            if (front.size() > 0) {
                front.erase(front.begin());
                size++;
                return true;
            } else {
                return false;
            }
        } 
        rear.pop_back();
        size++;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        if (front.empty()) {
            if (rear.size() > 0) {
                return *rear.begin();
            } else {
                return -1;
            }
        } 
        return front.back();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        if (rear.empty()) {
            if (front.size() > 0) {
                return *front.begin();
            } else {
                return -1;
            }
        } 
        return rear.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (size == capacity);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (size == 0);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
