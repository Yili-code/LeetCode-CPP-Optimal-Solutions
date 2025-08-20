class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (!head || left == right) return head;

    ListNode *dummy = new ListNode(0);

    dummy->next = head;

    // d1: node before left
    ListNode* d1 = dummy;
    for (int i = 0; i < left - 1; ++i) { d1 = d1->next; }

    // d2: first node in reverse section
    ListNode* d2 = d1->next;
    
    // reverse
    ListNode *curr = d2;
    ListNode *prev = nullptr;

    for (int i = 0; i < right - left + 1; ++i) {
      ListNode *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }

    // reconnect
    d1->next = prev;
    d2->next = curr;

    return dummy->next;
  }
};