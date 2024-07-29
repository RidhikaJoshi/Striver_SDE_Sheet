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
// Time Complexity: O(n)
// Space Complexity: O(n)
 class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode*>st;
        while(head!=NULL)
        {
            if(st.find(head)!=st.end())
                return head;
            st.insert(head);
            head=head->next;
        }
        return NULL;
    }
};
// Optimized Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        if(fast==NULL || fast->next==NULL)
            return NULL;
        if(slow!=fast)
            return NULL;
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};