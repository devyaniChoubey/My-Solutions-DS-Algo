https://www.interviewbit.com/problems/merge-two-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* merge(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL) return root2;
    if(root2 == NULL) return root1;

    root1->left = merge(root1->left, root2->left);
    root1->right = merge(root1->right, root2->right);

    root1->val += root2->val;

    return root1;
}
TreeNode* Solution::solve(TreeNode* root1, TreeNode* root2) {
    return merge(root1, root2);
}