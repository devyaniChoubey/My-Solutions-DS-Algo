https://www.interviewbit.com/problems/vertical-sum-of-a-binary-tree/

vector<int> Solution::verticalSum(TreeNode* root) {
    
    vector<int>ans;
    
    //node , x , y
    queue<pair<TreeNode*, pair<int, int>>>q;
    q.push({root, {0, 0}});
    map<int , map<int, vector<int>>>mp;
    
    while(!q.empty()){
        TreeNode* node = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        mp[y][x].push_back(node->val);
        
        if(node->left) q.push({node->left, {x+1, y-1}});
        if(node->right) q.push({node->right, {x+1, y+1}});
    }
    
    for(auto y : mp){
        int sum = 0;
        for(auto x : y.second){
            for(int num : x.second) sum += num;
        }
        ans.push_back(sum);
    }
    
    return ans;
}
