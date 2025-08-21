class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (!head) return head;

    ListNode *odd = new ListNode(0);
    ListNode *even = new ListNode(0);
    ListNode *oddCurr = odd;
    ListNode *evenCurr = even;
    ListNode *curr = head;
    int count = 1;
    
    while (curr) {
      ListNode *temp = curr;
      if (count % 2 == 1) {
        oddCurr->next = temp;
        oddCurr = temp;
      } else {
        evenCurr->next = temp;
        evenCurr = temp;
      }
      ++count;
      curr = curr->next;
    }

    oddCurr->next = even->next;
    evenCurr->next = nullptr;

    return odd->next;
  }
};