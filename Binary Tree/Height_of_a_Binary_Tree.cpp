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
// Time Complexity: O(n) : n is the number of nodes in the tree
// Space Complexity: O(n) : n is the number of nodes in the tree
// sotred in the recursive stack
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int leftSubtreeHeight=maxDepth(root->left);
        int rightSubtreeHeight=maxDepth(root->right);

        return 1+(max(leftSubtreeHeight,rightSubtreeHeight));
        
    }
};