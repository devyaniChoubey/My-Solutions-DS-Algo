https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

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
    TreeNode* createTree(int preStart, int preEnd, vector<int>& preorder,int postStart, int postEnd, vector<int>& postorder,map<int,int>&postMap){

        if(preStart > preEnd || postStart > postEnd) return NULL;

        TreeNode* node = new TreeNode(preorder[preStart]);

        if(preStart == preEnd) return node;

        int postId = postMap[preorder[preStart+1]];

        int numsLeft = postId - postStart + 1;

        node->left = createTree(preStart+1, preStart+numsLeft ,preorder, postStart, postId, postorder, postMap);
        
        node->right = createTree(preStart+numsLeft + 1, preEnd,preorder, postId+1, postEnd-1, postorder, postMap);

        return node; 
    }


    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int>postMap;

        for(int i=0;i < postorder.size();i++) postMap[postorder[i]] = i;

        return createTree(0, preorder.size() - 1,preorder, 0, postorder.size() - 1, postorder, postMap);
    }
};
