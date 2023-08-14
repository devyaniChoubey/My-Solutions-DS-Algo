https://www.interviewbit.com/problems/symmetric-binary-tree/

bool symmetry(TreeNode* root1 , TreeNode* root2){
    if(root1 == NULL || root2 == NULL) return (root1 == root2);

    if(root1->val != root2->val) return false;

    int left = symmetry(root1->left, root2->right);
    int right = symmetry(root1->right, root2->left);

    if(!left || !right) return false;

    return true;
}
int Solution::isSymmetric(TreeNode* root) {
    return symmetry(root->left, root->right);
}