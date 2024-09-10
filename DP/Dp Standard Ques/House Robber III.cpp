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
    int solve(TreeNode* root, bool canPick){
        if(root == NULL) return 0;
        
        int pick = 0;
        if(canPick){
           pick = root->val + solve(root->left, false) + solve(root->right, false);
        }

        int notPick = solve(root->left, true) + solve(root->right, true);

        return max(pick , notPick);
    }
    int rob(TreeNode* root) {
        return solve(root, true);
    }
};


class Solution {
public:
    int solve(TreeNode* root, unordered_map<TreeNode*,int>&dp){
        if(root == NULL) return 0;

        if(dp.find(root) != dp.end()) return dp[root];
        
        int pick = root->val;

        if(root->left){
            pick += rob(root->left->left);
            pick += rob(root->left->right);
        }

        if(root->right){
            pick += rob(root->right->left);
            pick += rob(root->right->right);
        }

        int notPick = rob(root->left) + rob(root->right);

        return dp[root] = max(pick, notPick);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        return solve(root, dp);
    }
};


class Solution {
public:
    unordered_map<TreeNode* , int>pickRes;
    unordered_map<TreeNode* , int>notPickRes;
    int solve(TreeNode* root, bool canPick){
        if(root==NULL) return 0;
        
        

        if(canPick){
            if(pickRes.find(root) != pickRes.end()) return pickRes[root];
            int pick = root->val + solve(root->left, false) +solve(root->right, false);
            int notPick = solve(root->left, true) +solve(root->right, true);
            return pickRes[root] = max(pick, notPick);
        }else{
            if(notPickRes.find(root) != notPickRes.end()) return notPickRes[root];
            int notPick = solve(root->left, true) +solve(root->right, true);
            return notPickRes[root] = notPick;
        }
    }
    int rob(TreeNode* root) {
        return solve(root,true);
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
    vector<int>solve(TreeNode* root){
        if(root == NULL) return {0, 0};

        vector<int>left = solve(root->left);
        vector<int>right = solve(root->right);

        //if we rob current house then we can not rob its children
        int rob = root->val + left[1] + right[1];

        //if we don't rob current house then we can rob its children
        int notRob = max(left[0], left[1]) + max(right[0] , right[1]);

        return {rob, notRob};
     }
    int rob(TreeNode* root) {
        vector<int>res = solve(root);
        return max(res[0] , res[1]);
    }
};





