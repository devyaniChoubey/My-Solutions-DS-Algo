https://leetcode.com/problems/recover-binary-search-tree/description/
//brute force

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
    int ind = 0;
    void inOrder(TreeNode* root, vector<int>&inorder){
        if(root == NULL) return;
        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }

    void swapTreeVal(TreeNode* root, vector<int>inorder){
        if(root == NULL) return;
        swapTreeVal(root->left, inorder);
        if(root->val != inorder[ind]){
            root->val = inorder[ind];
        }
        ind++;
        swapTreeVal(root->right, inorder);
    }
    void recoverTree(TreeNode* root) {
        vector<int>inorder;
        inOrder(root, inorder);
        sort(inorder.begin(), inorder.end());
        swapTreeVal(root, inorder);
    }
};


//optimised

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
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* middle = NULL; 
    TreeNode* last = NULL;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        
        inorder(root->left);
        if(prev != NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }else{
               last = root;
            } 
        }
        prev = root;
        inorder(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        first = NULL;middle = NULL;last = NULL;
        inorder(root);

        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};