https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

//Approach 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        
        if(root == p || root == q) return root;

        TreeNode* leftVal = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightVal = lowestCommonAncestor(root->right, p, q);

        if(leftVal != NULL && rightVal != NULL) return root;
        if(leftVal != NULL) return leftVal;
        if(rightVal != NULL) return rightVal;
        return NULL;
    }
};



//Approach 2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p , q);
        TreeNode* right = lowestCommonAncestor(root->right, p , q);
        
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else{
            return root;
        }
    }
};