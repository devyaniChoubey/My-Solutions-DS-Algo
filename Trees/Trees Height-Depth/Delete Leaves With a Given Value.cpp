https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

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
    TreeNode* solve(TreeNode* root, int target){
        if(root == NULL) return NULL;

        root->left = solve(root->left, target);
        root->right = solve(root->right , target);

        if(root->left == NULL && root->right == NULL && root->val == target){
            return NULL;
        }

        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root, target);
    }
};