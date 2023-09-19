https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/

https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/solutions/1612105/3-steps/
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

    bool find(TreeNode* root, int value, string &path){
        if(root->val == value) return true;

        if(root->left && find(root->left, value, path)) path.push_back('L');
        else if(root->right && find(root->right, value, path)) path.push_back('R');

        return !path.empty();

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s_p, d_p;
        find(root, startValue, s_p);
        find(root, destValue, d_p);

        while(!s_p.empty() && !d_p.empty() && s_p.back() == d_p.back()){
            s_p.pop_back();
            d_p.pop_back();
        }

        reverse(d_p.begin() , d_p.end());

        return string(s_p.size() , 'U') + d_p;
    }
};