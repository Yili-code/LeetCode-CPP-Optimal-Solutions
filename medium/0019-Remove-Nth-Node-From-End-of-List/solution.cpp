// Remove Nth Node From End of List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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