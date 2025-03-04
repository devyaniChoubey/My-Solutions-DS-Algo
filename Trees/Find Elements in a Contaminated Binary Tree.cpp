https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/


class FindElements {
public:
    unordered_set<int>st;

    void solve(TreeNode* root, unordered_set<int>&st, int par){
        if(!root) return;

        st.insert(par);

        solve(root->left, st, 2*par+1);
        solve(root->right, st, 2*par+2);
    }
    FindElements(TreeNode* root) {
        solve(root, st, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};
