#include <initializer_list>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

int main() {
  Solution sol;

  // tb 1
  ListNode *l1 = buildList({1, 2, 6, 3, 4, 5, 6});
  cout << "Before: ";
  printList(l1);
  ListNode *r1 = sol.removeElements(l1, 6);
  cout << "After (remove 6): ";
  printList(r1);
  freeList(r1);

  // tb 2：全部都是要刪除的值
  ListNode *l2 = buildList({7, 7, 7});
  cout << "\nBefore: ";
  printList(l2);
  ListNode *r2 = sol.removeElements(l2, 7);
  cout << "After (remove 7): ";
  printList(r2);
  freeList(r2);

  // tb 3：完全沒有匹配值
  ListNode *l3 = buildList({1, 2, 3});
  cout << "\nBefore: ";
  printList(l3);
  ListNode *r3 = sol.removeElements(l3, 9);
  cout << "After (remove 9): ";
  printList(r3);
  freeList(r3);

  // tb 4：頭尾都要刪除
  ListNode *l4 = buildList({5, 1, 2, 3, 5});
  cout << "\nBefore: ";
  printList(l4);
  ListNode *r4 = sol.removeElements(l4, 5);
  cout << "After (remove 5): ";
  printList(r4);
  freeList(r4);

  return 0;
}
