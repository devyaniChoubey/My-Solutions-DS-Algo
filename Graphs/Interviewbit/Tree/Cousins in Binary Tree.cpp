https://www.interviewbit.com/problems/cousins-in-binary-tree/


//Method 1
vector<int> Solution::solve(TreeNode* A, int B) {
    if(A->val == B) return {};

    queue<TreeNode*>q;
    q.push(A);
    
    int level = 0 , nodeLevel = 1e9;
    TreeNode* nodeSibling = NULL;
    bool found = false;


    vector<int>ans;
    while(!q.empty()){
        int size = q.size();
        
        for(int i=0;i < size;i++){
            TreeNode* node = q.front();
            q.pop();
            
            if(nodeLevel == level && node != nodeSibling && node->val != B){
                ans.push_back(node->val);
                found = true;
            }
            
            if(node->left){
                if(node->left->val == B){
                    nodeLevel = level+1;
                    nodeSibling = node->right;
                }
                q.push(node->left);
            }
            
            if(node->right){
                if(node->right->val == B){
                    nodeLevel = level+1;
                    nodeSibling = node->left;
                }
                q.push(node->right);
            }
        }

        if(found) return ans;
        level++;
    }
    
    return ans;
}


//Method 2

vector<int> Solution::solve(TreeNode* A, int B) {
    if(A->val == B) return {};
    
    queue<TreeNode*>q;
    q.push(A);
    

    vector<int>ans;
    bool found = true;
    while(!q.empty() && found){
        int size = q.size();
        
        for(int i=0;i < size;i++){
            TreeNode* node = q.front();
            q.pop();
            
            if((node->left && node->left->val == B) || (node->right && node->right->val == B)){
                found = false;
            }else{
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            } 
        }
    }
    
    while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }
    
    return ans;
}