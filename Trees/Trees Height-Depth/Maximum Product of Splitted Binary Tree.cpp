https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

class Solution {
public:
    long long totalSum = 0 , maxVal = -1e9;

    int dfsSum(TreeNode* root){
       if(root == NULL) return 0;
       int leftSum = dfsSum(root->left);
       int rightSum = dfsSum(root->right);
       int curSum = leftSum + rightSum + root->val;
       maxVal = max(maxVal, curSum * (totalSum - curSum));
       return curSum;
    }
    
    int maxProduct(TreeNode* root) {
        totalSum = dfsSum(root);
        dfsSum(root);
        return maxVal%int(1e9+7);
    }
};