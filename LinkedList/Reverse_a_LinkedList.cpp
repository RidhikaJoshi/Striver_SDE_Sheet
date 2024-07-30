#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
// Naive Solution
// Time Complexity: O(n)+O(n)
// Space complexity: O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        stack<int>st;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(st.size()!=0)
        {
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
        
    }
};
// Efficient Solution
// Time Complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *curr=head,*prev=NULL;
        while(curr!=NULL)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
        
    }
};