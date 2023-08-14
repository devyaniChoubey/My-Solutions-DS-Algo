https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Solution::minDepth(TreeNode* root) {
    if(root == NULL) return 0;

    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    
    if(root->left == NULL) return 1 + rh;
    if(root->right == NULL) return 1 + lh;

    return 1 + min(lh, rh);
}