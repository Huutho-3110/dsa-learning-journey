#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<ListNode *> sizeList(ListNode *head) {
  ListNode *curr = head;
  vector<ListNode *> saveList;

  while (curr != nullptr) {
    ListNode *pushNode = curr;
    curr = curr->next;
    pushNode->next = nullptr;
    saveList.push_back(pushNode);
  }
  return saveList;
}
class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    vector<ListNode *> tmp = sizeList(head);
    int n = tmp.size();
    for (int i = 1; i < n; i++) {
      ListNode *key = tmp[i];
      int j = i - 1;
      while (j >= 0 && key->val < tmp[j]->val) {
        tmp[j + 1] = tmp[j];
        j--;
      }
      tmp[j + 1] = key;
    }
    ListNode *newHead = new ListNode(0, nullptr);
    ListNode *current = newHead;
    newHead->next = current;
    for (ListNode *x : tmp) {
      current->next = x;
      current = current->next;
    }
    return newHead->next;
  }
  ListNode *insertionSortList2(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    ListNode *curr = head;
    while (curr != nullptr) {
      ListNode *currNext = curr->next;
      ListNode *prv = dummy;
      while (prv->next != nullptr && prv->next->val < curr->val) {
        prv = prv->next;
      }
      curr->next = prv->next;
      prv->next = curr;
      curr = currNext;
    }
    ListNode *sortedHead = dummy->next;
    delete dummy;
    return sortedHead;
  }
};