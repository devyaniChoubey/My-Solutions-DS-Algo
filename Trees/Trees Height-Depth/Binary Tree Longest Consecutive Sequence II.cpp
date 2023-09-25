https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/description/

class Solution {
public:
    int maxval = 0;
    
    int longestConsecutive(TreeNode* root) {
        longestPath(root);
        return maxval;
    }
    
    pair<int, int> longestPath(TreeNode* root) {
        if(root == NULL) return {0, 0};
        
        int inr = 1, dcr = 1;

        if(root->left != NULL){
            auto it = longestPath(root->left);  
            
            if(root->val == root->left->val-1){
                inr = it.first + 1;
            }

            if(root->val == root->left->val+1){
                dcr = it.second + 1;
            }
        }

        if(root->right != NULL){
            auto it = longestPath(root->right);

            if(root->val == root->right->val-1){
                inr = max(it.first + 1, inr);
            }

            if(root->val == root->right->val+1){
                dcr = max(it.second+1, dcr);
            }
        }

        maxval = max({maxval, dcr + inr - 1});
        return {inr, dcr};
    }
};