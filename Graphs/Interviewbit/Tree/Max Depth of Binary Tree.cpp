https://www.interviewbit.com/problems/max-depth-of-binary-tree/

int Solution::maxDepth(TreeNode* A) {
    if(A == NULL) return 0;
    
    int lh = maxDepth(A->left);
    int rh = maxDepth(A->right);
    
    return 1 + max(lh, rh);
}
