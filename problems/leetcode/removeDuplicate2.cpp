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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prv = dummy;
        ListNode *curr = dummy->next;
        while (curr != nullptr)
        {
            if (curr->next != nullptr && curr->val == curr->next->val)
            {
                while (curr->next != nullptr && curr->val == curr->next->val)
                {
                    curr = curr->next;
                }
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