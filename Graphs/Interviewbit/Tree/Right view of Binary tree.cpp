https://www.interviewbit.com/problems/right-view-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void rightView(TreeNode* root, int level, vector<int>&ans){
    if(root == NULL) return;
    
    if(level == ans.size()) ans.push_back(root->val);

    rightView(root->right, level+1, ans);
    rightView(root->left, level+1, ans);
}
vector<int> Solution::solve(TreeNode* root) {
    vector<int>ans;
    rightView(root, 0, ans);
    return ans;
}
