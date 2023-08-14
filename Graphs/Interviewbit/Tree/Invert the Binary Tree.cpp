
https://leetcode.com/problems/invert-binary-tree/description/


class Solution {
public:
    void dfs(TreeNode* root){
        if(root == NULL) return;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};