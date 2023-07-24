https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});

        int width = -1e9;
        while(!q.empty()){
            int size = q.size();
            int minOfCurLevel = q.front().second;
            int maxOfCurLevel = q.front().second;
            for(int i=0;i < size;i++){
                TreeNode* node = q.front().first;
                int index = q.front().second;
                q.pop();

                maxOfCurLevel = index;

                if(node->left) q.push({ node->left, 2*(long long)(index- minOfCurLevel) + 1});
                if(node->right) q.push({ node->right, 2*(long long)(index- minOfCurLevel) + 2});
            }

            width = max(width, ( maxOfCurLevel - minOfCurLevel + 1));
        }

        return width;
    }
};