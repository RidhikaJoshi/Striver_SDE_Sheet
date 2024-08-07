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
// Naive approach
// Time complexity: O(n)*2
// Space complexity: O(1)
// two pass approach
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int count=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        int node=count-n;
        if(node==0)
            return head->next;
        count=1;
        temp=head;
        while(count<node)
        {
            temp=temp->next;
            count++;

        }
        temp->next=temp->next->next;
        return head;
    }
};
// Optimized approach
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* slow=head,*fast=head;
        int count=0;
        while(count<n && fast!=NULL)
        {
            fast=fast->next;
            count++;
        }
        if(slow==fast || fast==NULL)
            return head->next;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
        

        
    }
};