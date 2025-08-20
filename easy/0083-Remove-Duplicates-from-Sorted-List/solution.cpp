class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return head;

    ListNode *current = head;
    while (current) {
      ListNode *nextNode = current;
      while (nextNode->next == current) { nextNode = nextNode->next; }
      current->next = nextNode->next;
      current = current->next;
    }

    return head;
  }
};