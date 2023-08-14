https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void flattenLinkedList(TreeNode* root, TreeNode* &right){
    if(root == NULL) return;
    
    flattenLinkedList(root->right, right);
    flattenLinkedList(root->left, right);
    
    root->right = right;
    root->left = NULL;
    
    right = root;
}
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* right = NULL;
    flattenLinkedList(A, right);
    return A;
}