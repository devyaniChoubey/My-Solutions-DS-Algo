https://leetcode.com/problems/binary-tree-paths/

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
    void solve(TreeNode* root, string path, vector<string>&ans){
        if(root == NULL) return;

        if(!root->left && !root->right){
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }

        solve(root->left, path+to_string(root->val)+"->", ans);

        solve(root->right, path+to_string(root->val)+"->", ans);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        solve(root, "", ans);
        return ans;
    }
};




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
    void solve(TreeNode* root, string &path, vector<string>&ans){
        if(!root->left && !root->right){
            ans.push_back(path);
            return;
        }
          
        if(root->left){
            path += "->" + to_string(root->left->val);
            solve(root->left,path, ans);
            int pos = path.rfind("->");
            path.erase(pos);
        }
        if(root->right){
            path += "->" + to_string(root->right->val);
            solve(root->right,path, ans);
            int pos = path.rfind("->");
            path.erase(pos);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = to_string(root->val);
        vector<string>ans;

        solve(root,path, ans);

        return ans;
    }
};