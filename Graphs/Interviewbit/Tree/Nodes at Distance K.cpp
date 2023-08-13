https://www.interviewbit.com/problems/nodes-at-distance-k/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::distanceK(TreeNode* A, int B, int K) {
    queue<TreeNode*>q;
    TreeNode* target;
    q.push(A);
    map<TreeNode*, TreeNode*>parentPointer;
    
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->val == B) target = node;
        
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
    
    int distance = 0;
    map<TreeNode*, int>vis;
    vis[target] = 1;
    
    vector<int>ans;
    bool reached = false;
    
    while(!q.empty()){
        int size = q.size();
        
        for(int j=0;j < size;j++){
            TreeNode* node = q.front();
            q.pop();
            
            if(distance == K){
                ans.push_back(node->val);
                reached = true;
            }
            
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
        if(reached == true) return ans;
        distance++;
    }
    
    return {-1};
}