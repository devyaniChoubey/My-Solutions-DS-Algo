https://www.interviewbit.com/problems/diagonal-traversal/

void dfs(TreeNode* root, int d, map<int, vector<int>>&mp){
    if(root == NULL) return;
    
    // Store all nodes of same
    // line together as a vector
    mp[d].push_back(root->val);
    
    // Increase the vertical
    // distance if left child
    dfs(root->left, d+1, mp);


    // Vertical distance remains
    // same for right child
    dfs(root->right, d, mp);
}

vector<int> Solution::solve(TreeNode* root) {
    map<int, vector<int>>mp;
    
    dfs(root, 0, mp);
    
    vector<int>ans;
    
    for(auto it:mp){
      ans.insert(ans.end(), it.second.begin(), it.second.end());
    }
    
    return ans;
}



//Method 2 optimised


// Every node will help to generate the next diagonal. We will push the element in the queue only when its left is available. 
// We will process the node and move to its right.


vector<int> Solution::solve(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    
    vector<int>ans;
    
    while(!q.empty()){
        int size = q.size();
        
        while(size--){
            TreeNode* temp = q.front();
            q.pop();
            
            
            while(temp){
                ans.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                
                temp = temp->right;
            }
        }
    }
    
    return ans;
}
