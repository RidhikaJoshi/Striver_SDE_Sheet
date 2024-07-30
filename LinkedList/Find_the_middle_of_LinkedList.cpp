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
// Space complexity: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        int count=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            count++;//counting number of nodes in the likedlist.
            temp=temp->next;
        }
        int mid=count/2+1;
        count=1;
        temp=head;
        while(count<mid)
        {
            count++;
            temp=temp->next;
        }
        return temp;
    }
};
// Efficient Solution
// Time Complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
};