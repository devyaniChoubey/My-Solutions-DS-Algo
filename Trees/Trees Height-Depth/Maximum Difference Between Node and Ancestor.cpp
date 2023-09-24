https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

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
    void dfs(TreeNode* root, int curMin, int curMax, int &ans){
        if(root == NULL) return;

        curMin = min({curMin, root->val});
        curMax = max({curMax, root->val});

        ans = max({ans, abs(root->val - curMin) ,  abs(root->val - curMax)});

        dfs(root->left, curMin, curMax, ans);
        dfs(root->right, curMin, curMax, ans);

    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, root->val, root->val, ans);
        return ans;
    }
};