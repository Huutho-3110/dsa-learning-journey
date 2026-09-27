#include <bits/stdc++.h>
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
  ListNode *partition(ListNode *head, int x) {
    ListNode *fr = new ListNode();
    ListNode *bk = new ListNode();
    ListNode *frtmp = new ListNode(0, fr);
    ListNode *bktmp = new ListNode(0, bk);
    ListNode *curr = head;
    while (curr != nullptr) {
      if (curr->val < x) {
        ListNode *pushNode = curr;
        curr = curr->next;
        pushNode->next = nullptr;
        fr->next = pushNode;
        fr = fr->next;
      } else {
        ListNode *pushNode = curr;
        curr = curr->next;
        pushNode->next = nullptr;
        bk->next = pushNode;
        bk = bk->next;
      }
    }
    bk->next = nullptr;
    fr->next = bktmp->next->next;
    ListNode *newHead = frtmp->next->next;
    ListNode *headFrDummy = frtmp->next; 
    ListNode *headBkDummy = bktmp->next; 

    delete frtmp;
    delete bktmp;
    delete headFrDummy;
    delete headBkDummy;

    return newHead;
  }
};