https://www.interviewbit.com/problems/balanced-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findHeight(TreeNode* A){
    if(A == NULL) return 0;
    
    int lh = findHeight(A->left);
    int rh = findHeight(A->right);
    
    if(lh == -1 || rh == -1) return -1;
    if(abs(lh-rh) > 1) return -1;
    return 1 + max(lh, rh);
}
int Solution::isBalanced(TreeNode* A) {
    if(findHeight(A) == -1) return 0;
    else return 1;
}
