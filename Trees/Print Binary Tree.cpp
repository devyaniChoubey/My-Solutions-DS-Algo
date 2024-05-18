https://leetcode.com/problems/print-binary-tree/description/

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
    int treeHeight(TreeNode* root){
        if(root == NULL) return 0;

        int lh = treeHeight(root->left);
        int rh = treeHeight(root->right);

        return 1 + max(lh, rh);
    }

    void solve(TreeNode* root, int row, int col, vector<vector<string>>&ans,int height){
        if(root == NULL) return;

        ans[row][col] = to_string(root->val);
        solve(root->left, row+1, col - pow(2, height - row - 1), ans,height);
        solve(root->right, row+1, col + pow(2, height - row - 1), ans,height);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = treeHeight(root) - 1;
        int row = height + 1;
        int col = pow(2 , row) - 1;
        vector<vector<string>>ans(row, vector<string>(col, ""));
        solve(root, 0, (col-1)/2, ans, height);
        return ans;
    }
};