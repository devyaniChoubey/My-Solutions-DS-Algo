https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    void solve(TreeNode* root,string &path, vector<string>&temp){
        if(root == NULL) return;
        
        path.push_back(char(root->val + 'a'));

        if(root->left == NULL && root->right == NULL){
            string copied = path;
            reverse(copied.begin() , copied.end());
            if(temp.size() && (temp.back().compare(copied) > 0)){
                temp.pop_back();
                temp.push_back(copied);
            }else if(temp.size() == 0){
                temp.push_back(copied);
            }
        }

        solve(root->left, path, temp);
        solve(root->right, path, temp);
        path.pop_back();

    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string>temp;
        string path = "";
        solve(root, path, temp);
        return temp[0];
    }
};