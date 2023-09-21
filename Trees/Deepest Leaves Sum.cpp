https://leetcode.com/problems/deepest-leaves-sum/description/


class Solution {
public:
    void leavesSum(TreeNode* &root, int &ans, int curLevel, int &maxLevel){
        if(root == NULL) return;

        if(maxLevel < curLevel){
            ans  = root->val;
        }else if (maxLevel == curLevel) ans += root->val;

        maxLevel = max(maxLevel, curLevel);

        leavesSum(root->left, ans,curLevel+1, maxLevel);
        leavesSum(root->right, ans,curLevel+1, maxLevel);
    }

    int deepestLeavesSum(TreeNode* root) {
        int maxLevel = 0;
        int ans = 0;
        leavesSum(root, ans,0, maxLevel);
        return ans;
    }
};