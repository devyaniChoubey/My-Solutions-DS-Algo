https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/


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
    TreeNode* bstPreorder(vector<int>& preorder, int preStart, int preEnd) {
        if(preStart > preEnd) return NULL;

        TreeNode* node = new TreeNode(preorder[preStart]);
        
        int preStartRight;
        for(int i=preStart;i <= preEnd;i++){
            if(preorder[i] > preorder[preStart]){
                preStartRight = i;
                break;
            }
        }

        node->left = bstPreorder(preorder, preStart+1 , preStartRight-1);
        node->right = bstPreorder(preorder, preStartRight , preEnd);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstPreorder(preorder, 0 ,  preorder.size() - 1);
    }
};


//Optimised


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
    int ind = 0;
    TreeNode* bstPreorder(vector<int>& preorder, int max) {
        if(ind >= preorder.size() || preorder[ind] > max) return NULL;

        TreeNode* node = new TreeNode(preorder[ind]);
        ind++;
        node->left = bstPreorder(preorder, node->val);
        node->right = bstPreorder(preorder, max);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstPreorder(preorder, INT_MAX);
    }
};