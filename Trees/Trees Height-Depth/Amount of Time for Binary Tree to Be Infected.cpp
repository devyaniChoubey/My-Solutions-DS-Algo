https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

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
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*>q;
        q.push(root);
        map<TreeNode*, TreeNode*>parentPointer;
        TreeNode* startNode;
        map<TreeNode*, int>vis;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start) startNode = node;

            if(node->left){
                q.push(node->left);
                parentPointer[node->left] = node; 
            }

            if(node->right){
                q.push(node->right);
                parentPointer[node->right] = node; 
            }
        }

        q.push(startNode);
        vis[startNode] = 1;
        int totalTimeTaken = 0;

        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            for(int i=0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    vis[node->left] = 1;
                    q.push(node->left);
                    flag = 1;
                }

                if(node->right && !vis[node->right]){
                    vis[node->right] = 1;
                    q.push(node->right);
                    flag = 1;
                }

                if(parentPointer[node] && !vis[parentPointer[node]]){
                    vis[parentPointer[node]] = 1;
                    q.push(parentPointer[node]);
                    flag = 1;
                }
            }

            if(flag == 1) totalTimeTaken++;
        }

        return totalTimeTaken;

        
    }
};