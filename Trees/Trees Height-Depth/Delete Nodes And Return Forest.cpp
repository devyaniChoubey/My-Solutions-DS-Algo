https://leetcode.com/problems/delete-nodes-and-return-forest/description/

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
    void deleteNodes(TreeNode* &root,  unordered_set<int>&toDelete, vector<TreeNode*>&res){
        if(root == NULL) return;

        deleteNodes(root->left, toDelete, res);
        deleteNodes(root->right, toDelete, res);

        if(toDelete.find(root->val) != toDelete.end()){
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            root = NULL;
            delete root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>toDelete(to_delete.begin() , to_delete.end());

        vector<TreeNode*>res;

        deleteNodes(root, toDelete, res);

        if(root) res.push_back(root);

        return res;
    }
};