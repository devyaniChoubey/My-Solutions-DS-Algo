https://leetcode.com/problems/find-distance-in-a-binary-tree/description/

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
    int result;

    int dfs(TreeNode* root, int p, int q){
        if(root == NULL) return -1;

        int left = dfs(root->left, p, q);
        int right = dfs(root->right, p, q);

        if(root->val == p || root->val == q){
            if(left < 0 && right < 0){
              return 0;
            }

            result = 1 + ((left >= 0) ? left : right);
            
            return -1;
        }

        if(left >= 0 && right >= 0){
            result = 2 + left + right;
            return -1;
        }

        if(left >= 0) return 1 + left;
        if(right >= 0) return 1 + right;

        return -1;
    }

    int findDistance(TreeNode* root, int p, int q) {
        if(p == q) return 0;
        
        result = -1;
        dfs(root, p, q);
        return result;
    }
};