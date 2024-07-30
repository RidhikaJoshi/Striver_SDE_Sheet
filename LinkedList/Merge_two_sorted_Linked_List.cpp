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
 // Time complexity: O(n+m)*2
 // Space complexity: O(n+m)
 // two traversal
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        vector<int>res;
        ListNode* t1=list1,*t2=list2;
        // creating array in sorted order
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->val<t2->val)
            {
                res.push_back(t1->val);
                t1=t1->next;
            }
            else
            {
                res.push_back(t2->val);
                t2=t2->next;
            }
        }
        while(t1!=NULL)
        {
            res.push_back(t1->val);
            t1=t1->next;
        }
        while(t2!=NULL)
        {
            res.push_back(t2->val);
                t2=t2->next;
        }
        // creating linkedlist out of sorted array
        ListNode* newhead=NULL,*temp=NULL;
        for(int i=0;i<res.size();i++)
        {
            ListNode* curr=new ListNode(res[i]);
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
        return newhead;

        
    }
};
// Optimized approach
// Time complexity: O(n+m)
// Space complexity: O(1)
// single traversal
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* t1=list1,*t2=list2;
        ListNode* newhead=NULL,*temp=NULL;
        while(t1!=NULL && t2!=NULL)
        {
            ListNode* curr;
            if(t1->val<t2->val)
            {
                curr=t1;
                t1=t1->next;
            }
            else
            {
                curr=t2;
                t2=t2->next;
            }
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
            ListNode* curr=t1;
            t1=t1->next;
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
            ListNode* curr=t2;
            t2=t2->next;
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
        return newhead;
        
    }
};