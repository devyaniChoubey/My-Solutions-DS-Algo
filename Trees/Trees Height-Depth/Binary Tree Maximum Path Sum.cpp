https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

Solution 1
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
    int maxi = -1e9;
    int maxSum(TreeNode* root){
        if(root == NULL) return 0;
        
        int maxVal = root->val;
        if(ls > 0) maxVal += ls;
        if(rs > 0) maxVal += rs;

        maxi = max(maxi, maxVal);

        if(max(ls,rs) > 0) return root->val + max(ls,rs);
        else return root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return maxi;
    }
};




Solution 2

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
    int maxPath(TreeNode* root, int &ans){
       if(root == NULL) return 0;

        int leftSum = max(0, maxPath(root->left, ans));
        int rightSum = max(0, maxPath(root->right, ans));

        ans = max(ans, root->val+ leftSum + rightSum);
        return root->val + max(leftSum , rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPath(root, ans);
        return ans;
    }
};