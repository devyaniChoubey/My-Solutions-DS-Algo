
https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

TreeNode * constructTree(int inStart, int inEnd, vector<int>& inorder, int postStart, int postEnd, vector<int>& postorder, map<int, int>&inMap){
    if(inStart > inEnd || postStart > postEnd) return NULL;
    
    TreeNode* node = new TreeNode(postorder[postEnd]);
    int numsLeft = inMap[node->val] - inStart;
    
    node->left = constructTree(inStart, inMap[node->val] - 1, inorder, postStart, postStart + numsLeft - 1, postorder, inMap);
    node->right = constructTree(inMap[node->val] + 1, inEnd, inorder, postStart + numsLeft, postEnd - 1, postorder, inMap);
    
    return node;
}

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int, int>inMap;

    for(int i=0;i < inorder.size();i++) inMap[inorder[i]] = i;

    return constructTree(0, inorder.size() - 1, inorder, 0,  postorder.size() - 1, postorder, inMap);
}
