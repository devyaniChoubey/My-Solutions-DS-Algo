https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/


int sum(TreeNode* n, int s) {
    if (n == NULL) return 0;
    if (n->right == NULL && n->left == NULL) return (s * 10 + n->val) % 1003;
    return (sum(n->left, (s * 10 + n->val) % 1003) + sum(n->right, (s * 10 + n->val) % 1003)) % 1003;
}


int Solution::sumNumbers(TreeNode* root) {
    return sum(root, 0);
}
