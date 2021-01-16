// Question Link: https://www.hackerrank.com/contests/a2sv-contest-2/challenges/detect-whether-a-linked-list-contains-a-cycle/

bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;
    while (fast) {
        slow = slow->next;
        fast = ((fast && fast->next) ? fast->next->next : NULL);
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
