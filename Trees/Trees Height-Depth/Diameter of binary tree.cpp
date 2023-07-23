//Recursive

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
    int maxi = 0;
    int diameter(TreeNode* root){
        if(root == NULL) return 0;

        int lh = diameter(root->left);
        int rh = diameter(root->right);
        
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int leftH = diameter(root->left);
        int rightH = diameter(root->right);

        maxi = max(maxi, leftH + rightH);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxi;

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
    int maxDiameter = 0;
    int diameter(TreeNode* root){
        if(root == NULL) return 0;

        int lh = diameter(root->left);
        int rh = diameter(root->right);
        
        maxDiameter = max(lh + rh, maxDiameter);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxDiameter;
    }
};