https://www.interviewbit.com/problems/burn-a-tree/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A, int B) {
    map<TreeNode*, TreeNode*>parentPointer;
    queue<TreeNode*>q;
    TreeNode* target;
    q.push(A);
    
    while(!q.empty()){
        TreeNode* node = q.front();
        
        if(node->val == B) target = node;
        
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
    
    q.push(target);
    map<TreeNode*, int>vis;
    vis[target] = 1;
    int time = 0;
    
    while(!q.empty()){
        int size = q.size();
        for(int k=0;k < size;k++){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left && !vis[node->left]){
                q.push(node->left);
                vis[node->left] = 1;
            }
            
            if(node->right && !vis[node->right]){
                q.push(node->right);
                vis[node->right] = 1;
            }
            
            if(parentPointer[node] && !vis[parentPointer[node]]){
                q.push(parentPointer[node]);
                vis[parentPointer[node]] = 1;
            }
        }
        time++;
    }
    
    return time-1;
}
