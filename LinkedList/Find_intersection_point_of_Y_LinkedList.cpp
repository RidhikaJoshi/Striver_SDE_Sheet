#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
// Naive Solution
// Time Complexity=O(n+m) where n and m are the number of nodes in the two linked lists
// Space Complexity=O(n+m) where n and m are the number of nodes in the two linked lists
class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
       unordered_set<Node*>st;
       while(head1!=NULL)
       {
           st.insert(head1);
           head1=head1->next;
       }
       while(head2!=NULL)
       {
           if(st.find(head2)!=st.end())
                return head2->data;
            st.insert(head2);
            head2=head2->next;
       }
       return -1;
    }
};
// Efficient Solution
// Time Complexity=O(n+m) where n and m are the number of nodes in the two linked lists
// Space Complexity=O(1)
class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
       Node* a=head1,*b=head2;
       while(a!=b)
       {
           if(a->next==NULL)
                a=head2;
            else
                a=a->next;
            
            if(b->next==NULL)
                b=head1;
            else
                b=b->next;
       }
       if(a==b)
            return a->data;
        
        return -1;
    }
};