
https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        
        vector<int>ans;
        if(root == NULL) return ans;
        map<int, int>mp;
        queue<pair<Node* , int>>q;
        q.push({root, 0});
        
        while(!q.empty()){
            Node* node = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(node->left) q.push({node->left, y-1});
            if(node->right) q.push({node->right, y+1});
            
            if(mp.find(y) == mp.end()){
                mp[y] = node->data;
            }
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }

};