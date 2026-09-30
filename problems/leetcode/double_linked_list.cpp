#include <bits\stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution {
public:
  Node *flatten(Node *head) {
    if (head == nullptr)
      return nullptr;
    stack<Node *> st;
    st.push(head);
    Node *prvNode = nullptr;
    while (!st.empty()) {
      Node *curr = st.top();
      st.pop();
      if (prvNode != nullptr) {
        prvNode->next = curr;
        curr->prev = prvNode;
      }
      if (curr->next != nullptr) {
        st.push(curr->next);
      }
      if (curr->child != nullptr) {
        st.push(curr->child);
        curr->child = nullptr;
      }
      prvNode = curr;
    }
    return head;
  }
};