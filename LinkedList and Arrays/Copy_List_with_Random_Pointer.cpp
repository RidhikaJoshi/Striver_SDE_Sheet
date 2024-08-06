#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N)

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if(head==NULL)
            return NULL;
        unordered_map<Node*,Node*>m;
        // previous node,newNode
        Node *temp=head;
        while(temp!=NULL)
        {
            if(m.find(temp)==m.end())
            {
                Node *currNode=new Node(temp->val);
                m[temp]=currNode;
            }
            if(temp->next!=NULL && m.find(temp->next)==m.end())
            {
                Node* nextNode=new Node(temp->next->val);
                m[temp->next]=nextNode;
            }
            if(temp->random!=NULL && m.find(temp->random)==m.end())
            {
                Node *newRandom=new Node(temp->random->val);
                m[temp->random]=newRandom;
            }
            Node *currNode=m[temp];
            currNode->next=m[temp->next];
            currNode->random=m[temp->random];
            temp=temp->next;
        }
        return m[head];
        
    }
};