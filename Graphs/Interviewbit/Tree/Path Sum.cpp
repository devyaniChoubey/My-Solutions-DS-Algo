https://www.interviewbit.com/problems/path-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solve(TreeNode* root,int sum, int B){
    if(root == NULL) return false;
    
    if(root->left == NULL && root->right == NULL){
        if(sum + root->val == B) return true;
    }
    
    bool left = solve(root->left, sum + root->val, B);
    bool right = solve(root->right, sum + root->val, B);
    
    if(left || right) return true;
    
    return false;
}
int Solution::hasPathSum(TreeNode* root, int B) {
    return solve(root, 0, B);
}
