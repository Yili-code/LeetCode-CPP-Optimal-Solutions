class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (ListNode * node : lists) {
      while (node) {
        minHeap.push(node->val);
        node = node->next;
      }
    }

    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;

    while (!minHeap.empty()) {
      ListNode *newNode = new ListNode(minHeap.top());
      minHeap.pop();
      curr->next = newNode;
      curr = newNode;
    }

    return dummy->next;
  }
};