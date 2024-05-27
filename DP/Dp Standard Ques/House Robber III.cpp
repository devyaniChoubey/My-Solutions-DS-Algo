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
    int solve(TreeNode* root, bool canPick){
        if(root == NULL) return 0;
        
        int pick = 0;
        if(canPick){
           pick = root->val + solve(root->left, false) + solve(root->right, false);
        }

        int notPick = solve(root->left, true) + solve(root->right, true);

        return max(pick , notPick);
    }
    int rob(TreeNode* root) {
        return solve(root, true);
    }
};





