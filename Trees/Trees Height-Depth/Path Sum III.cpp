https://leetcode.com/problems/path-sum-iii/description/


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
    void calculatePaths(TreeNode* root, long long targetSum, int &path){
        if(root == NULL) return;

        targetSum -= root->val;

        if(targetSum == 0) path++;

        calculatePaths(root->left, targetSum, path);
        calculatePaths(root->right, targetSum, path);
    }
    void dfs(TreeNode* root, int targetSum, int &paths){
        if(root == NULL) return;
        
        int path = 0;
        calculatePaths(root, targetSum, path);
        paths += path;

;
        dfs(root->left, targetSum, paths);
        dfs(root->right, targetSum, paths);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int paths = 0;
        dfs(root, targetSum, paths);
        return paths;
    }
};