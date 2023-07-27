https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        if(root == NULL) {
            return new TreeNode(val);
        }

        while(cur){
            if(val > cur->val){
                if(cur->right == NULL) {
                    cur->right = new TreeNode(val);
                    break;
                }
                cur = cur->right;
            }else{
                if(cur->left == NULL) {
                    cur->left = new TreeNode(val);
                    break;
                }
                cur = cur->left;
            }
        }

        return root;
    }
};