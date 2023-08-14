https://www.interviewbit.com/problems/identical-binary-trees/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A == NULL || B == NULL) return (A == B);
    
    if(A->val != B->val) return false;
    
    int left = isSameTree(A->left, B->left);
    int right = isSameTree(A->right, B->right);
    
    if(!left || !right) return false;
    
    return true;
}
