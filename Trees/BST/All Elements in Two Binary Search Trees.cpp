https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/

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
    void inOrderTraversal(TreeNode* root, vector<int>&res){
        if(root == NULL) return;

        inOrderTraversal(root->left, res);
        res.push_back(root->val);
        inOrderTraversal(root->right, res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>inOrder1, inOrder2;
        inOrderTraversal(root1, inOrder1);
        inOrderTraversal(root2, inOrder2);

        int i=0, j = 0, n = inOrder1.size() , m = inOrder2.size();

        vector<int>ans;

        while(i < n && j < m){
            if(inOrder1[i] <= inOrder2[j]){
                ans.push_back(inOrder1[i]);
                i++;
            }else{
                ans.push_back(inOrder2[j]);
                j++;
            }
        }

        while(i < n){
            ans.push_back(inOrder1[i]);
            i++;
        }

        while(j < m){
            ans.push_back(inOrder2[j]);
            j++;
        }

        return ans;
    }
};




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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>st1, st2;

        vector<int>ans;

        while((root1 != NULL) || (root2 != NULL) || (!st1.empty()) || (!st2.empty())){
            while(root1 != NULL){
                st1.push(root1);
                root1 = root1->left;
            }

            while(root2 != NULL){
                st2.push(root2);
                root2 = root2->left;
            }

            if((st2.empty()) || (!st1.empty() && st1.top()->val <= st2.top()->val)){
                root1 = st1.top();
                st1.pop();
                ans.push_back(root1->val);
                root1 = root1->right;
            }else{
                root2 = st2.top();
                st2.pop();
                ans.push_back(root2->val);
                root2 = root2->right;
            }

        }

        return ans;
    }
};