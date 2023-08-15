https://www.interviewbit.com/problems/covered-uncovered-nodes/


// If we perform a level order traversal or a breadth first search,
// we can see that the first and last node of each level are uncovered nodes, the rest are covered.

// So, we keep two counters, one for uncovered and covered. Then, simply add the value in each counter
// respectively for each level, then return the absolute difference of the two.


long Solution::coveredNodes(TreeNode* root) {
    queue<TreeNode*>q;
    q.push(root);
    
    long uncovered_sum = 0, total_sum = 0;
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i=0;i < size;i++){
            TreeNode* node = q.front();
            q.pop();
            
            if(i == 0){
                uncovered_sum += node->val;
            }else if(i == size - 1){
                uncovered_sum += node->val;
            }
            
            total_sum += node->val;
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }  
    }
    
    return abs(total_sum - 2*uncovered_sum);
}
