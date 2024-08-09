#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> leftView(Node *root)
{
    if(root==NULL)
        return {};
    queue<Node*>q;
    q.push(root);
    vector<int>res;
    while(q.size()!=0)
    {
        int countSize=q.size();
        for(int i=0;i<countSize;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(i==0)
                res.push_back(curr->data);
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
    return res;
}
