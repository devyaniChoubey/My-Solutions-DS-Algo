https://www.interviewbit.com/problems/least-common-ancestor/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool pExist = false, qExist = false;
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if(root == NULL) return NULL;
    
    if(root->val == p || root->val == q){
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left != NULL && right != NULL){
        return root;
    }
    if(left != NULL) return left;
    else return right;
}

void dfs(TreeNode* root, int p, int q){
    if(root == NULL) return;
    if(root->val == p) pExist = true;
    if(root->val == q) qExist = true;
    dfs(root->left, p, q);
    dfs(root->right, p, q);
}

int Solution::lca(TreeNode* root, int p, int q) {
    pExist = false; qExist = false;
    dfs(root, p, q);
    TreeNode* LCA = lowestCommonAncestor(root, p, q);
    
    if(LCA != NULL && ((p == q) || (pExist && qExist))) return LCA->val;
    else return -1;
}