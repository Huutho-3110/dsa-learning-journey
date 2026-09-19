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
  int countSize(ListNode *head) {
    ListNode *curr = head;
    int cnt = 0;
    while (curr != nullptr) {
      cnt++;
      curr = curr->next;
    }

    return cnt;
  }
  int pairSum(ListNode *head) {
    int sz = countSize(head);
    stack<int> l;
    ListNode *curr = head;
    int i = 0;
    int maxSum = -10;
    for (int i = 0; i < (sz / 2); i++) {
      l.push(curr->val);
      curr = curr->next;
    }
    for (int i = sz / 2; i < sz; i++) {
      int tmp = l.top();
      if ((tmp + curr->val) > maxSum)
        maxSum = (tmp + curr->val);
      l.pop();
      curr = curr->next;
    }
    return maxSum;
  }
};