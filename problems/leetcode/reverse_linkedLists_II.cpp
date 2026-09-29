#include <bits\stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right)
      return head;
    ListNode *dummy = new ListNode(0, head);
    ListNode *prv = dummy;
    for (int i = 0; i < left - 1; i++) {
      prv = prv->next;
    }
    ListNode *curr = prv->next;
    for (int i = 0; i < right - left; i++) {
      ListNode *nodeNext = curr->next;
      curr->next = nodeNext->next;
      nodeNext->next = prv->next;
      prv->next = nodeNext;
    }
    ListNode *newHead = dummy->next;
    delete dummy;
    return newHead;
  }
};