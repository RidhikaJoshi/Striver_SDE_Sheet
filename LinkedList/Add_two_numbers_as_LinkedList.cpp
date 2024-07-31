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
//Optimal Solution
// Time Complexity=O(max(n,m)) where n and m are the number of nodes in the two linked lists
// Space Complexity=O(max(n,m)) where n and m are the number of nodes in the two linked lists
 class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int sum=0,carry=0;
        ListNode* t1=l1,*t2=l2;
        ListNode *newhead=NULL,*temp=NULL;
        while(t1!=NULL && t2 !=NULL)
        {
            sum=t1->val+t2->val+carry;
            t1=t1->next;
            t2=t2->next;
            carry=sum/10;
            sum=sum%10;
            ListNode *curr=new ListNode(sum);
            if(newhead==NULL)
            {
                newhead=curr;
                temp=curr;
            }
            else
            {
                temp->next=curr;
                temp=temp->next;
            }
        }
        while(t1!=NULL)
        {
            sum=t1->val+carry;
            t1=t1->next;
            carry=sum/10;
            sum=sum%10;
            ListNode* curr=new ListNode(sum);
            if(newhead==NULL)
            {
                newhead=curr;
                temp=curr;
            }
            else
            {
                temp->next=curr;
                temp=temp->next;
            }
        }
        while(t2!=NULL)
        {
             sum=t2->val+carry;
             t2=t2->next;
            carry=sum/10;
            sum=sum%10;
            ListNode* curr=new ListNode(sum);
            if(newhead==NULL)
            {
                newhead=curr;
                temp=curr;
            }
            else
            {
                temp->next=curr;
                temp=temp->next;
            }
        }
        if(carry!=0)
        {
            ListNode* curr=new ListNode(carry);
            temp->next=curr;
        }
        return newhead;
    }
};