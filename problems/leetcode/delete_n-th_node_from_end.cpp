#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int sizeList(ListNode *head) {
  ListNode *curr = head;
  int cnt = 0;
  while (curr != nullptr) {
    cnt++;
    curr = curr->next;
  }
  return cnt;
}
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == nullptr)
      return head;
    if (n == 0)
      return head;
    int sz = sizeList(head);
    ListNode *dummy = new ListNode(0, head);
    ListNode *prv = dummy;
    ListNode *delNode = head;
    int tmp = sz - n;
    while (tmp--) {
      prv = delNode;
      delNode = delNode->next;
    }
    prv->next = delNode->next;
    delete delNode;
    ListNode *newHead = dummy->next;
    delete dummy;
    return newHead;
  }
};