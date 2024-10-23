
https://leetcode.com/problems/inorder-successor-in-bst/


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = NULL;
        while(root){
            if(p->val < root->val){
                ans = root;
                root = root->left;
            }else{
                root = root->right;
            }
        }

        return ans;
    }
};