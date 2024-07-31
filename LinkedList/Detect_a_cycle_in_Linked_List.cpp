#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
// Naive Solution
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
       unordered_set<Node*>st;
       while(head!=NULL)
       {
           if(st.find(head)!=st.end())
            return true;
            
            st.insert(head);
            head=head->next;
           
       }
       return false;
    }
};
// Efficient Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
       Node* slow=head,*fast=head;
       while(fast!=NULL && fast->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast)
            return true;
       }
       return false;
    }
};