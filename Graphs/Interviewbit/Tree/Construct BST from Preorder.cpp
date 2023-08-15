https://www.interviewbit.com/problems/construct-bst-from-preorder/

int ind = 0;
TreeNode* bstPreorder(vector<int>& preorder, int max) {
    if(ind >= preorder.size() || preorder[ind] > max) return NULL;

    TreeNode* node = new TreeNode(preorder[ind]);
    ind++;
    node->left = bstPreorder(preorder, node->val);
    node->right = bstPreorder(preorder, max);
    return node;
}
TreeNode* Solution::constructBST(vector<int>& preorder) {
    ind = 0;
    return bstPreorder(preorder, INT_MAX);
}