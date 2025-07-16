class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy(0, head);
    ListNode *cur = &dummy;

    while (cur->next != nullptr) {
      if (cur->next->val == val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }

    return dummy.next;
  }
};

// 建立 linked list
ListNode *buildList(initializer_list<int> vals) {
  ListNode dummy(0);
  ListNode *cur = &dummy;
  for (int v : vals) {
    cur->next = new ListNode(v);
    cur = cur->next;
  }
  return dummy.next;
}

// 輸出 linked list
void printList(ListNode *head) {
  while (head) {
    cout << head->val;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

// 釋放 linked list 記憶體
void freeList(ListNode *head) {
  while (head) {
    ListNode *tmp = head;
    head = head->next;
    delete tmp;
  }
}