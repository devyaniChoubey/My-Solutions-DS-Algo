https://leetcode.com/problems/find-leaves-of-binary-tree/description/


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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>>ans;
        getHeight(root, ans);
        return ans;
    }

    int getHeight(TreeNode* root,vector<vector<int>>&ans){
        if(root == NULL) return 0;
        
        int lh = getHeight(root->left,ans);
        int rh = getHeight(root->right,ans);

        int height =  1 + max(lh, rh);

        if (ans.size() < height) {
            ans.push_back(vector<int>());
        }

        ans[height-1].push_back(root->val);

        return height;
    }
};