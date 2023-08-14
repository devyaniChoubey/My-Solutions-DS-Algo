https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

//Solution 1

class Solution {
public:
    long long ans = 0;
    bool solve(TreeNode* root , vector<int>&v){
        if(root == NULL) return false;

        v.push_back(root->val);

        long long sum = 0;
        if(root->left == NULL && root->right == NULL){
            int size = v.size();
            for(int i=0;i < v.size();i++){
                sum += v[i]*(pow(10, size - 1 - i));
            }
            ans += sum;
        }

        bool left = solve(root->left, v);
        bool right = solve(root->right, v);

        if(!left && !right){
            v.pop_back();
        }

        return false;
    }
    int sumNumbers(TreeNode* root) {
        vector<int>v;
        solve(root, v);
        return ans;
    }
};

//Solution 2

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }

    int solve(TreeNode* root, int sum){
        if(root == NULL) return 0;

        if(root->left == NULL && root->right == NULL) return (sum*10 + root->val);

        return solve(root->left, sum*10 + root->val) + solve(root->right, sum*10 + root->val);
    }
};