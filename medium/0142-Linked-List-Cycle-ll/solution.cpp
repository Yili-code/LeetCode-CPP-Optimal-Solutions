// Linked List Cycle II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) {
        ListNode *index1 = fast;
        ListNode *index2 = head;
        int pos = 1;
        while (index1 != index2) {
          index1 = index1->next;
          index2 = index2->next;
          pos++;
        }

        return index1;
      }
    }
    return nullptr;
  }
};