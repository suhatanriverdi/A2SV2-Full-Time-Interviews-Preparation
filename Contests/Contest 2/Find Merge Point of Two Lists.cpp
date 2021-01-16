// Question Link: https://www.hackerrank.com/contests/a2sv-contest-2/challenges/find-the-merge-point-of-two-joined-linked-lists/

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    unordered_set<SinglyLinkedListNode*> s;
    for (SinglyLinkedListNode *walk = head1; walk; walk = walk->next) {
        s.insert(walk);
    }
    for (SinglyLinkedListNode *walk = head2; walk; walk = walk->next) {
        if (s.find(walk) != s.end()) {
            return walk->data;
        }
    }
    return -1;
}
