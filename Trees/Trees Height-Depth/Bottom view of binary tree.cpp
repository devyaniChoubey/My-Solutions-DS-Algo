https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector <int>ans;
        queue<pair<Node*,int>>q;
        q.push({root, 0});
        map<int, int>mp;
        
        while(!q.empty()){
            Node* node = q.front().first;
            int y = q.front().second;
            q.pop();
            
            mp[y] = node->data;
            
            if(node->left) q.push({node->left, y-1});
            if(node->right) q.push({node->right, y+1});
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};