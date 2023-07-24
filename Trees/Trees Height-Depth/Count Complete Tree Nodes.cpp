https://leetcode.com/problems/count-complete-tree-nodes/description/

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
    int findLeftHeight(TreeNode* root){
        int leftHeight = 0;
        while(root != NULL){
           leftHeight++;
           root = root->left;
        }
        return leftHeight;
    }

    int findRightHeight(TreeNode* root){
        int rightHeight = 0;
        while(root != NULL){
           rightHeight++;
           root = root->right;
        }
        return rightHeight;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = findLeftHeight(root); 
        int rh = findRightHeight(root);

        if(lh == rh) return (1<<lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};