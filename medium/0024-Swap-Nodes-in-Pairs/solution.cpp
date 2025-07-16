class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0, head);
    ListNode *curr = &dummy;

    int count = 0;
    while (curr->next) {
      curr = curr->next;
      count++;
    }
    curr = &dummy;

    if (n > count) {
      return dummy.next;
    } else if (n == count) {
      return dummy.next->next;
    } else {
      for (int i = 0; i < count - n; ++i) {
        curr = curr->next;
      }
      curr->next = curr->next->next;
      return dummy.next;
    }
  }
};