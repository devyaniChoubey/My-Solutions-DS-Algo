/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        vector<int>inorder;
        vector<int>preorder;

        if(root == NULL) return postorder;

        stack<pair<TreeNode*, int>>st;
        st.push({root, 1});
        
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int step = st.top().second;
            st.pop();

            if(step == 1){
                preorder.push_back(node->val);
                step++;
                st.push({node, step});
                if(node->left) st.push({node->left, 1});
            }else if(step == 2){
                inorder.push_back(node->val);
                step++;
                st.push({node, step});
                if(node->right) st.push({node->right, 1});
            }else if (step == 3){
                postorder.push_back(node->val);
            }
        }

        return postorder;
    }
};