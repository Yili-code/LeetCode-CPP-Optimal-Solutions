class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || k == 0) return head;

    // compute size and reach tail
    int size = 1;
    ListNode* tail = head;
    while (tail->next) {
      tail = tail->next;
      ++size;
    }
    
    int move = size - k % size;
    if (size == move) return head;

    // Find the new tail
    ListNode* newTail = head;
    for (int i = 0; i < move - 1; ++i) {
      newTail = newTail->next;
    }

    // Disconnect the new tail node with new head node
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;

    // Connect the old tail with old head
    tail->next = head;

    return newhead;
  }
};