#include<bits/stdc++.h>
using namespace std;
// Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector <int>res;
    	int level=0;
    	if(root==NULL)
    	    return {};
    	 queue<Node*>q;
    	 q.push(root);
    	 while(q.size()!=0)
    	 {
    	     int countSize=q.size();
    	     vector<int>r;
    	     for(int i=0;i<countSize;i++)
    	     {
    	         Node* curr=q.front();
    	         q.pop();
    	         r.push_back(curr->data);
    	         if(curr->left!=NULL)
    	            q.push(curr->left);
    	           if(curr->right!=NULL)
    	            q.push(curr->right);
    	     }
    	     if(level%2!=0)
    	     {
    	         reverse(r.begin(),r.end());
    	     }
    	     for(int i=0;i<r.size();i++)
    	        res.push_back(r[i]);
    	       level++;
    	 }
    	 return res;
    }
};
// Optimized Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        if(root==NULL)
            return {};
    	stack<Node*>st1,st2;
    	st1.push(root);
    	vector<int>res;
    	while(st1.size() || st2.size()!=0)
    	{
    	    while(st1.size()!=0)
    	    {
    	        Node* curr=st1.top();
    	        st1.pop();
    	        res.push_back(curr->data);
    	        if(curr->left!=NULL)
    	            st2.push(curr->left);
    	        if(curr->right!=NULL)
    	            st2.push(curr->right);
    	    }
    	    while(st2.size()!=0)
    	    {
    	        Node* curr=st2.top();
    	        st2.pop();
    	        res.push_back(curr->data);
    	        if(curr->right!=NULL)
    	            st1.push(curr->right);
    	        if(curr->left!=NULL)
    	            st1.push(curr->left);
    	     
    	    }
    	}
    	return res;
    }
};