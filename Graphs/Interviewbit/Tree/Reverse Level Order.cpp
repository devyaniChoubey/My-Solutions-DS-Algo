https://www.interviewbit.com/problems/reverse-level-order/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root) { 
  vector<int>ans;
  if(root == NULL) return ans;
  queue<TreeNode*>q;
  stack<int>st;
  q.push(root);
  
  while(!q.empty()){
    TreeNode* node = q.front();
    q.pop();
    st.push(node->val);

    if(node->right) q.push(node->right);
    if(node->left) q.push(node->left);
  }
  
  while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
  }
  
  return ans;
}
