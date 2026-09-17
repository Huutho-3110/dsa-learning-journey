#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
};
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }

        return head;
    }
    ListNode *deleteDuplicates2(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *curr = head;
        ListNode *dummy = new ListNode();
        ListNode **h = &dummy;
        bool done = false;
        while (!done)
        {
            while (curr != nullptr && curr->next != nullptr && curr->val == curr->next->val)
            {
                curr = curr->next;
            }
            if (curr != nullptr && curr->next != nullptr && curr->val != curr->next->val)
            {
                (*h)->next = curr;
                h = &((*h)->next);
                curr = curr->next;
            }
            if (curr->next == nullptr)
            {

                (*h)->next = curr;
                h = &((*h)->next);
                done = true;
            }
        }
        return dummy->next;
    }
};
