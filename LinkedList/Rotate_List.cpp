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
// Time Complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head==NULL)
            return NULL;
        int count=0;
        ListNode *fast=head,*slow=head,*curr=head;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        k=k%count;
        if(k==0)
            return head;
        count=0;
        while(count!=k )
        {
            count++;
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;
 
    }
};