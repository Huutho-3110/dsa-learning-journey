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

int getLength(ListNode *head)
{
    int count = 0;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }

    return count;
}
ListNode *rotate(ListNode(**head))
{
    ListNode *curr = *head;
    ListNode *currNext = *head;
    while (currNext->next != nullptr)
    {
        curr = currNext;
        currNext = currNext->next;
    }
    currNext->next = *head;
    *head = currNext;
    curr->next = nullptr;
    return *head;
}
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;
        int length = getLength(head);
        k = k % length;
        while (k--)
        {
            rotate(&head);
        }
        return head;
    }
};