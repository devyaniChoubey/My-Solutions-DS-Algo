https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

//Brute Force

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
    void inOrder(TreeNode* root,vector<int>&inorder){
        if(root == NULL) return;

        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inOrder(root, inorder);

        int left = 0;
        int right = inorder.size() - 1;

        while(left < right){
            if(inorder[left] + inorder[right] > k){
                right--;
            }else if(inorder[left] + inorder[right] < k){
               left++;
            }else {
               return true;
            }
        }

        return false;
    }
};