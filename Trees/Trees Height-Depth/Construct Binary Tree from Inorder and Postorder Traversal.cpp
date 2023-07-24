https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode* buildUniqTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>&inMap){
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* node = new TreeNode(postorder[postEnd]);
        int nodeIndex = inMap[node->val];
        int numsLeft = nodeIndex - inStart;

        node->left = buildUniqTree(postorder, postStart , postStart + numsLeft - 1, inorder, inStart, nodeIndex - 1, inMap);
        node->right = buildUniqTree(postorder, postStart + numsLeft , postEnd - 1, inorder, nodeIndex + 1, inEnd, inMap);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>inMap;
        for(int i=0;i < inorder.size();i++) inMap[inorder[i]] = i;
        return buildUniqTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }
};            