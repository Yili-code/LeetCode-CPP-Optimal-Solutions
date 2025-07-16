// Add Two Numbers
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *curr1 = l1;
    ListNode *curr2 = l2;

    ListNode *result = new ListNode(0);
    ListNode *curr = result;

    while (curr1 || curr2) {
      int x = curr1 ? curr1->val : 0;
      int y = curr2 ? curr2->val : 0;

      int sum = x + y;
      if (carry == 1)
        ++sum;
      if (sum >= 10) {
        sum = sum - 10;
        carry = 1;
      } else {
        carry = 0;
      }

      if (curr1)
        curr1 = curr1->next;
      if (curr2)
        curr2 = curr2->next;

      curr->next = new ListNode(sum);
      curr = curr->next;
    }
    if (carry == 1) {
      curr->next = new ListNode(1);
    }
    return result->next;
  }
};