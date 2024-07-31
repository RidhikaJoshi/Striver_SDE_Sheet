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
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
       // using stack as extra space
       stack<int>st;
       int countNode=1;
       Node* temp=head;
       while(temp->next!=NULL)
       {
           temp=temp->next;
           countNode++;
       }
      
       int mid=countNode/2;
       int count=1;
       temp=head;
       while(count<=mid)
       {
           st.push(temp->data);
           temp=temp->next;
           count++;
       }
      if(countNode%2!=0)
            temp=temp->next;
        while(st.size()!=0)
        {
            if(st.top()!=temp->data)
            {
                //cout << st.top() << " "<< temp->data << endl;
                 return false;
            }
               
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};
// Efficient Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
  public:
    // Function to check whether the list is palindrome.
    Node* reverse(Node* curr)
    {
        Node* prev=NULL;
        while(curr!=NULL)
        {
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        // using slow and fast pointer to reach the middle of the linkedlist
        Node* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* mid=slow;
        Node* newhead=reverse(slow);
        while(head!=mid)
        {
            if(head->data!=newhead->data)
                    return false;
            head=head->next;
            newhead=newhead->next;
        }
       return true;
    }
};