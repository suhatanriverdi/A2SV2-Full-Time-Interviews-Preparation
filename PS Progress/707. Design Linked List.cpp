// Question Link: https://leetcode.com/problems/design-linked-list/

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int n) {
//         val = n;
//         next = NULL;
//     }
// }
class MyLinkedList {
private:
    ListNode* head;
    int length;
    ListNode* tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    
    bool isEmpty() {
        return (length == 0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (isEmpty() || index >= length) {
            return -1;
        }
        ListNode* walk = head;
        int curIndex = 0;
        for (; curIndex < index; walk = walk->next, curIndex++) {};
        return walk->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *newNode = new ListNode(val);
        if (isEmpty()) {
            head = newNode;
            tail = head;
        } else {
            ListNode *tmp = head;
            head = newNode;
            newNode->next = tmp;
        }
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *newNode = new ListNode(val);
        if (isEmpty()) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > length) {
            return;
        }
        // Add At Head
        if (isEmpty() || index == 0) {
            addAtHead(val);
            return;
        }
        // Add At Tail
        else if (index == length) {
            addAtTail(val);
            return;
        }
        else {
            ListNode *newNode = new ListNode(val);
            ListNode* walk = head;
            int curIndex = 0;
            for (; curIndex < index - 1; walk = walk->next, curIndex++) {};
            ListNode* tmp = walk->next;
            walk->next = newNode;
            newNode->next = tmp;
        }
        length++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= length || isEmpty()) {
            return;
        }
        // Delete Head
        else if (isEmpty() || index == 0) {
            ListNode* toDelete = head;
            head = head->next;
            delete(toDelete);
        }
        else {
            ListNode* walk = head;
            int curIndex = 0;
            for (; curIndex < index - 1; walk = walk->next, curIndex++) {};
            ListNode* tmp = walk->next;
            walk->next = walk->next->next;
            delete(tmp);
        }
        length--;
        updateTail();
    }
    
    void updateTail() {
        if (isEmpty()) {
            tail = NULL;
            return;
        }
        ListNode* walk = head;
        for (; walk->next; walk = walk->next) {};
        tail = walk;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
