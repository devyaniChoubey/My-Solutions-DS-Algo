https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int distance = 0;
        map<TreeNode*, TreeNode*>parentPointer;

        queue<TreeNode*>q;
        q.push(root);

        vector<int>ans;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parentPointer[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                parentPointer[node->right] = node;
                q.push(node->right);
            }
        }

        set<TreeNode*>vis;
        vis.insert(target);
        q.push(target);

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(distance == k){
                    ans.push_back(node->val);
                }

                if(node->left){
                    if(vis.find(node->left) == vis.end()){
                        q.push(node->left);
                        vis.insert(node->left);
                    }
                }

                if(node->right){
                    if(vis.find(node->right) == vis.end()){
                        q.push(node->right);
                        vis.insert(node->right);
                    }
                }

                if(parentPointer[node] != NULL && vis.find(parentPointer[node]) == vis.end()){
                    q.push(parentPointer[node]);
                    vis.insert(parentPointer[node]);
                }
             
            }
            if(distance == k) {
                return ans;
            }

            distance++;
        }

        return ans;

    }
};
