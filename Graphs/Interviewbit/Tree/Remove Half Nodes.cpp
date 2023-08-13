https://www.interviewbit.com/problems/remove-half-nodes/

The idea is to use post-order traversal to solve this problem efficiently.
We first process the left children, then right children, and finally the node itself.
So we form the new tree bottom up, starting from the leaves towards the root.
By the time we process the current node, both its left and right subtrees were already processed.

Time Complexity of the above solution is O(N) as it does a simple traversal of binary tree.
Space Complexity- O(1)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* newTree(TreeNode* root){
    if(root == NULL) return NULL;
    
    root->left = newTree(root->left);
    root->right = newTree(root->right);
    
    if(root->left != NULL && root->right == NULL) return root->left;
    if(root->left == NULL && root->right != NULL) return root->right;
    else return root;
    
}
TreeNode* Solution::solve(TreeNode* A) {
    return newTree(A);
}
