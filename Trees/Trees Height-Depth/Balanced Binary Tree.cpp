https://leetcode.com/problems/balanced-binary-tree/description/


//naive


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
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int leftH = height(root->left);
        int rightH = height(root->right);

        if(abs(leftH - rightH) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(left == false || right == false) return false;

        return true;
    }
};




//Optimised

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
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(lh - rh) > 1 || lh == -1 || rh == -1) return -1;
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
       if(height(root) == -1) return false;
       return true;
    }
};