https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    TreeNode* buildUniqTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>&inMap){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* node = new TreeNode(preorder[preStart]);

        int nodeIndex = inMap[preorder[preStart]];

        int numsLeft = nodeIndex - inStart;

        node->left = buildUniqTree(preorder, preStart+1, preStart + numsLeft, inorder, inStart , nodeIndex - 1, inMap);
        node->right = buildUniqTree(preorder, preStart + numsLeft + 1, preEnd, inorder, nodeIndex + 1 , inEnd, inMap);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>inMap;

        int n = preorder.size();
        for(int i=0;i < inorder.size();i++) inMap[inorder[i]] = i;

        return buildUniqTree(preorder, 0, n-1, inorder, 0 , n - 1, inMap);
    }
};
