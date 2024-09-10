https://leetcode.com/problems/linked-list-in-binary-tree/?envType=daily-question&envId=2024-09-07

class Solution {
public:
    bool dfs(TreeNode* root, ListNode* head){
        if(!head) return true;
        if(!root) return false;

        if(root->val != head->val) return false;

        return dfs(root->left, head->next) || dfs(root->right, head->next);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        
        if(dfs(root, head)) return true;

        return isSubPath(head, root->left) ||  isSubPath(head, root->right);
    }
};