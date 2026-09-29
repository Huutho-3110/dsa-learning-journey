#include <bits\stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int sizeList(ListNode *head) {
  int cnt = 0;
  ListNode *curr = head;
  while (curr != nullptr) {
    cnt++;
    curr = curr->next;
  }
  return cnt;
}
ListNode *merge(ListNode *leftSort, ListNode *rightSort) {
  ListNode *dummy = new ListNode(0);
  ListNode *check = dummy;
  ListNode *currL = leftSort;
  ListNode *currR = rightSort;
  while (currL != nullptr && currR != nullptr) {
    if (currL->val <= currR->val) {
      check->next = currL;
      check = check->next;
      currL = currL->next;
    } else {
      check->next = currR;
      check = check->next;
      currR = currR->next;
    }
  }
  if (currL != nullptr) {
    check->next = currL;
  }
  if (currR != nullptr) {
    check->next = currR;
  }
  ListNode *newHead = dummy->next;
  delete dummy;
  return newHead;
}

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *midNode = slow;
    ListNode *headRight = midNode->next;
    midNode->next = nullptr;
    ListNode *leftSort = sortList(head);
    ListNode *rightSort = sortList(headRight);
    return merge(leftSort, rightSort);
  }
};