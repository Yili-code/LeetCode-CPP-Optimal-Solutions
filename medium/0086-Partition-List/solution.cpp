class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    // dummy heads for two partitions
    ListNode *d_g = new ListNode(0);
    ListNode *d_s = new ListNode(0);

    ListNode *gHead = d_g;
    ListNode *sHead = d_s;

    while (head) {
        if (head->val >= x) {
            d_g->next = head;
            d_g = head;
        } else if (head->val < x) {
            d_s->next = head;
            d_s = head;
        }
        head = head->next;
    }

    d_g->next = nullptr;
    d_s->next= gHead->next;
    return sHead->next;
  }
};