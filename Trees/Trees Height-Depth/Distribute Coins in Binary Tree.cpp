https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

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
    int dfs(TreeNode* root, int &result){
        if(root == NULL) return 0;
        
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        
        root->val += (left + right);
        result += abs(root->val - 1);
        return root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
};