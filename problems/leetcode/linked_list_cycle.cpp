#include <bits\stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fastNode = head;
    ListNode *slowNode = head;
    while (fastNode != nullptr && fastNode->next != nullptr) {
      fastNode = fastNode->next->next;
      slowNode = slowNode->next;
      if (fastNode == slowNode)
        return true;
    }
    return false;
  }
};