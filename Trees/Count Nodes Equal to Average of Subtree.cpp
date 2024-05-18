https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

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
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(root == NULL) return {0,0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int curSum = left.first + right.first + root->val;
        int curNodes = left.second + right.second + 1;

        if(curSum/curNodes == root->val) ans++;

        return {curSum, curNodes};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};