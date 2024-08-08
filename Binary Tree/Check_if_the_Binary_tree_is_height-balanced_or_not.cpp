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
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// Recursion call stack
class Solution {
public:
    int heightOfTree(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l=heightOfTree(root->left);
        int r=heightOfTree(root->right);
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root)
    {
        if(root==NULL)
            return true;
        int leftSubTreeHeight=heightOfTree(root->left);
        int rightSubTreeHeight=heightOfTree(root->right);
    
        if(abs(leftSubTreeHeight-rightSubTreeHeight)<=1  && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
        
    }
};