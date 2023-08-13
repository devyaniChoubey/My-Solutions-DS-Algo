https://www.interviewbit.com/problems/consecutive-parent-child/

int cnt = 0;
TreeNode* dfs(TreeNode* A){
    if(A == NULL) return NULL;
    
    TreeNode* left = dfs(A->left);
    TreeNode* right = dfs(A->right);
    
    if(left != NULL && (abs(left->val - A->val) == 1)) cnt++;
    if(right != NULL && (abs(right->val - A->val) == 1)) cnt++;
    
    return A;
}
int Solution::consecutiveNodes(TreeNode* A) {
    cnt = 0;
    dfs(A);
    return cnt;
}
