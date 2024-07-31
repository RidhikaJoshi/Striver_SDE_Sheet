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
 // Time Complexity: O(1)
// Space Complexity: O(1)

 class Solution {
public:
    void deleteNode(ListNode* node)
    {
        ListNode* temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        
    }
};