
https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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
    void countGoodNode(TreeNode* root, int &goodNodeCnt, int maxVal){
        if(root == NULL) return;

        if(root->val >= maxVal) goodNodeCnt++;

        maxVal = max(maxVal, root->val);

        countGoodNode(root->left, goodNodeCnt, maxVal);
        countGoodNode(root->right, goodNodeCnt, maxVal);
    }
    int goodNodes(TreeNode* root) {
        int goodNodeCnt = 0;
        countGoodNode(root, goodNodeCnt, root->val);
        return goodNodeCnt;
    }
};