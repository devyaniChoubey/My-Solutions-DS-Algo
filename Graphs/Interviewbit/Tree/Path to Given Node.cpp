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
 
bool dfs(TreeNode* A, int B, vector<int>&ans){
    // if root is NULL
    // there is no path
    if(A == NULL) return false;
    
    // push the node's value in 'arr'
    ans.push_back(A->val);

    // if it is the required node
    if(A->val == B) return true;
    
    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node

    bool left = dfs(A->left, B, ans);
    bool right = dfs(A->right, B, ans);
    
    if(left || right) return true;

    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'aan'and then return false
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    dfs(A, B, ans);
    return ans;
}
