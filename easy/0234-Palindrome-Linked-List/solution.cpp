class Solution {
public:
  bool isPalindrome(ListNode *head) {
    // Fine the middle node 
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse the second half
    ListNode *secondHalf = reverse(slow->next);

    // Compare the first half and reversed second half
    while (secondHalf) {
      if (secondHalf->val != head->val) {
        return false;
      } else {
        secondHalf = secondHalf->next;
        head = head->next;
      }
    }

    return true;
  }

private:
  ListNode* reverse(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr) {
      ListNode *nextNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextNode;
    }

    return prev;
  }
};