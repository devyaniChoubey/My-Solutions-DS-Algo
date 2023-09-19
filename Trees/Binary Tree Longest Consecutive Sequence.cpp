https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/

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
    void dfs(TreeNode* root, int cur, int target, int &ans){
        if(root == NULL) return;

        if(root->val == target) cur++;
        else cur = 1;

        ans = max(ans, cur);

        dfs(root->left, cur, root->val + 1 , ans);
        dfs(root->right, cur, root->val + 1 , ans);
    }
    int longestConsecutive(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, 0, root->val, ans);
        return ans;
    }
};