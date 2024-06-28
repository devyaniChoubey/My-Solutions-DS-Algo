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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();

            if(t1 == NULL && t2 == NULL) continue;
            if(t1 == NULL || t2 == NULL) return false;

            if(t1->val != t2->val) return false;

            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
};