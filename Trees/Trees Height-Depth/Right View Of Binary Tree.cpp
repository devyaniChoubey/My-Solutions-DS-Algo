https://leetcode.com/problems/binary-tree-right-side-view/description/

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

//Solution 1
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root, 0});
        map<int,int>mp;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int x = q.front().second;
            q.pop();

            if(mp.find(x) == mp.end()) mp[x] = node->val;

            if(node->right) q.push({node->right, x+1});
            if(node->left) q.push({node->left, x+1});
        }

        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }
};


//Solution 2 Optimised

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
    void rightView(TreeNode* node, vector<int>&ans, int level){
        if(node == NULL) return;
        if(level == ans.size()) {
            ans.push_back(node->val);
        }
        rightView(node->right, ans, level+1);
        rightView(node->left, ans, level+1); 
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level = 0;
        rightView(root, ans, level);
        return ans;
    }
};