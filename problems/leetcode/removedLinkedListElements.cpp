#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *curr = dummy->next;
        ListNode *prv = dummy;
        while (curr != nullptr)
        {
            if (curr->val == val)
            {
                prv->next = curr->next;
            }
            else
            {
                prv = prv->next;
            }
            curr = curr->next;
        }
        ListNode *newH = dummy->next;
        delete dummy;
        return newH;
    }
};