// Question Link: https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
    list<int> doublyLinkedList;
    int size, available;
public:
    MyCircularQueue(int k) {
        size = k;
        available = k;
    }
    
    // New element is always inserted at "Rear" position
    bool enQueue(int value) {
        if (isFull() == false) {
            doublyLinkedList.push_back(value);
            available--;
            return true;
        }
        return false;
    }
    
    // The element is always deleted from "Front" position
    bool deQueue() {
        if (isEmpty() == false) {
            doublyLinkedList.pop_front();
            available++;
            return true;
        }
        return false;
    }
    
    int Front() {
        return !isEmpty() ? doublyLinkedList.front() : -1;
    }
    
    int Rear() {
        return !isEmpty() ? doublyLinkedList.back() : -1;
    }
    
    bool isEmpty() {
        return available == size;
    }
    
    bool isFull() {
        return available == 0;
    }
};