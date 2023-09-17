https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/

https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/solutions/2758013/level-depth/
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
    int level[100001] = {}, depth[100001] = {};
    int d1[100001] = {}, d2[100001] = {};

    int traverse(TreeNode* root, int lev){
        if(root == NULL) return 0;

        level[root->val] = lev;
        depth[root->val] = 1 + max(traverse(root->left, lev+1) , traverse(root->right, lev+1));

        if(d1[lev] < depth[root->val]){
            d2[lev] = d1[lev];
            d1[lev] = depth[root->val];
        }else if(d2[lev] < depth[root->val]){
            d2[lev] = depth[root->val];
        }

        return depth[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverse(root, 0);
        
        for(int i=0;i < queries.size();i++){
            int q = queries[i];
            int l = level[q];
            queries[i] = (depth[q] == d1[l]) ? l + d2[l] - 1 : l + d1[l] - 1;
        }

        return queries;
    }
};