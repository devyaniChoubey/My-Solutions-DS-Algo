

/*Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<int>&path, vector<vector<int>>&ans){
        if(root == NULL) return;
        
        path.push_back(root->data);
        if(!root->left && !root->right){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        solve(root->left, path, ans);
        solve(root->right, path, ans);
        path.pop_back();
        
    }
    vector<vector<int>> Paths(Node* root) {
        
        // code here
        vector<vector<int>>ans;
        vector<int>path;
        solve(root, path, ans);
        return ans;
        
    }
};