/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.*/

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
// Time=O(N+M) +O(NlogN)+O(N+M)
// Space=O(N+M)
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        vector<int> arr;
        ListNode *temp = list1;
        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        temp = list2;
        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        ListNode *head = NULL;
        temp = NULL;
        int i = 0;
        while (i < arr.size())
        {
            ListNode *curr = new ListNode(arr[i]);
            i++;
            if (head == NULL)
            {
                head = curr;
                temp = curr;
            }
            else
            {
                temp->next = curr;
                temp = temp->next;
            }
        }
        return head;
    }
};

// Otimised Solution
//  Time=O(N+M)
//  space=O(N+M)
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        int x = 0;
        ListNode *head = NULL, *curr = NULL;
        ListNode *temp1 = list1, *temp2 = list2;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val < temp2->val)
            {
                x = temp1->val;
                temp1 = temp1->next;
            }
            else
            {
                x = temp2->val;
                temp2 = temp2->next;
            }
            ListNode *t = new ListNode(x);
            if (head == NULL)
            {
                head = t;
                curr = t;
            }
            else
            {
                curr->next = t;
                curr = curr->next;
            }
        }
        while (temp1 != NULL)
        {
            ListNode *t = new ListNode(temp1->val);
            if (head == NULL)
            {
                head = t;
                curr = t;
            }
            else
            {
                curr->next = t;
                curr = curr->next;
            }
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            ListNode *t = new ListNode(temp2->val);
            if (head == NULL)
            {
                head = t;
                curr = t;
            }
            else
            {
                curr->next = t;
                curr = curr->next;
            }
            temp2 = temp2->next;
        }
        return head;
    }
};
// Time=O(N+M)
// Space=O(1)

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = NULL, *temp = NULL;
        ListNode *temp1 = list1, *temp2 = list2;
        ListNode *ans;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val < temp2->val)
            {
                ans = temp1;
                temp1 = temp1->next;
                ans->next = NULL;
            }
            else
            {
                ans = temp2;
                temp2 = temp2->next;
                ans->next = NULL;
            }

            if (head == NULL)
            {
                head = ans;
                temp = ans;
            }
            else
            {
                temp->next = ans;
                temp = temp->next;
            }
        }
        while (temp1 != NULL)
        {
            ans = temp1;
            temp1 = temp1->next;
            if (head == NULL)
            {
                head = ans;
                temp = ans;
            }
            else
            {
                temp->next = ans;
                temp = temp->next;
            }
        }
        while (temp2 != NULL)
        {
            ans = temp2;
            temp2 = temp2->next;
            if (head == NULL)
            {
                head = ans;
                temp = ans;
            }
            else
            {
                temp->next = ans;
                temp = temp->next;
            }
        }
        return head;
    }
};