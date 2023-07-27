https://leetcode.com/problems/validate-binary-search-tree/description/

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

inorder traversal of BST is in ascending order;

class Solution {
public:
    long val = LONG_MIN;
    bool isBST = true;

    void isBSTCheck(TreeNode* root){
        if(root == NULL) return;

        isBSTCheck(root->left);
        if(root->val > val){
            val = root->val;
        }else{
            isBST = false;
        }
        isBSTCheck(root->right);
    }
    bool isValidBST(TreeNode* root) {
        isBSTCheck(root);
        return isBST;
    }
};



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
    bool isBST(TreeNode* root, long min, long max){
        if(root == NULL) return true;

        if(root->val > min && root->val < max){}
        else return false;

        bool left = isBST(root->left, min, root->val);
        bool right = isBST(root->right, root->val, max);

        if(!left || !right) return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};