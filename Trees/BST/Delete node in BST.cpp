https://leetcode.com/problems/delete-node-in-a-bst/description/


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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key){
            return helper(root);
        }
        
        TreeNode* cur = root;
        while(cur){
            if(key < cur->val){
                if(cur->left != NULL && cur->left->val == key){
                    cur->left = helper(cur->left);
                    break;
                }else cur = cur->left;
            }else{
                if(cur->right != NULL && cur->right->val == key){
                    cur->right = helper(cur->right);
                    break;
                }else cur = cur->right;
            }
        }

        return root;
        
    }


    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }

        TreeNode* leftChild = root->left;
        TreeNode* leftLastRight = findLeftLastRight(leftChild);
        leftLastRight->right = root->right;
        return leftChild;
    }

    TreeNode* findLeftLastRight(TreeNode* root){
        if(root->right == NULL) return root;
        while(root->right){
            root = root->right;
        }
        return root;
    }
};