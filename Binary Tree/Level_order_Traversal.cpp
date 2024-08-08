#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
    };
// Time Complexity: O(N) : N= Number of nodes in the tree
// Space Complexity: O(N) : N= Number of nodes in the tree
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {
            int countSize=q.size();
            vector<int>r;
            for(int i=0;i<countSize;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                r.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);

            }
            if(r.size()>0)
                res.push_back(r);
        }
        return res;
        
    }
};