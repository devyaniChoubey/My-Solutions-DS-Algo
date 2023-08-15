https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

TreeNode* constructTree(int preStart, int preEnd, vector<int>& preorder, int inStart, int inEnd, vector<int>& inorder, map<int, int>&inMap){
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* node = new TreeNode(preorder[preStart]);
    int numsLeft = inMap[node->val] - inStart;

    node->left = constructTree(preStart+1, preStart + numsLeft ,preorder, inStart, inMap[node->val] - 1,inorder, inMap);
    node->right = constructTree(preStart + numsLeft + 1, preEnd ,preorder, inMap[node->val] + 1,inEnd, inorder, inMap);

    return node;
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int>inMap;

    for(int i=0;i < inorder.size(); i++) inMap[inorder[i]] = i;
    return constructTree(0, preorder.size()-1,preorder, 0, inorder.size() - 1,inorder, inMap);
}