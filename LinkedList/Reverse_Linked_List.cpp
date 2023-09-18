/*Given the head of a singly linked list, reverse the list, and return the reversed list.*/

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
// Space=O(N);

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;
        stack<int> st;
        ListNode *temp = head;
        while (temp != NULL)
        {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

// Optimised Solution
//  Time=O(N)
//  Space =O(1)
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head, *prev = NULL;
        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
int main()
{
    int n, x;
    cin >> n;
    ListNode *head = NULL, *temp = NULL;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        ListNode *curr = new ListNode(x);
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
    Solution s;
    head = s.reverseList(head);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}