/*Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};
// Naive Solution
// Time=O(N)*2
// Space=O(1)
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head, *ans = NULL;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int mid = (count / 2) + 1;
        temp = head;
        while (mid)
        {
            mid--;
            ans = temp;
            temp = temp->next;
        }
        return ans;
    }
};

// Optimised Solution
// Using slow and fast pointer
// Time=O(N)
// Space=O(1)
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};