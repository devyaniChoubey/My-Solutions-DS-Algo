https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool findPath(TreeNode* root, int target, vector<int>&path){
    if(root == NULL) return false;
    
    path.push_back(root->val);
    if(root->val == target) return true;
    
    bool leftVal = findPath(root->left, target, path);
    bool rightVal = findPath(root->right, target, path);
    
    if(!leftVal && !rightVal){
        path.pop_back();
        return false;
    }
    
    return true;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>path;
    findPath(A, B, path);
    return path;
}