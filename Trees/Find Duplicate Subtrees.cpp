https://leetcode.com/problems/find-duplicate-subtrees/description/

https://leetcode.com/problems/find-duplicate-subtrees/editorial/
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
    string traverse(TreeNode* root, unordered_map<string, int>&mp, vector<TreeNode*>&res){
        if(root == NULL) return "";

        string representation = "(" + traverse(root->left, mp, res) + ")" + to_string(root->val) + "(" + traverse(root->right, mp, res) + ")";

        mp[representation]++;

        if(mp[representation] == 2) res.push_back(root);

        return representation;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int>mp;
        vector<TreeNode*>res;
        traverse(root, mp, res);
        return res;
    }
};



//optimised

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
    int traverse(TreeNode* root, unordered_map<int, int>&cnt,unordered_map<string, int>&tripletToID, vector<TreeNode*>&res){
        if(root == NULL) return 0;

        string triplet = to_string(traverse(root->left, cnt,tripletToID, res)) + "," + to_string(root->val) + "," + to_string(traverse(root->right, cnt,tripletToID, res));

        if(!tripletToID.count(triplet)){
            tripletToID[triplet] = tripletToID.size() + 1;
        }

        int id = tripletToID[triplet];

        cnt[id]++;

        if(cnt[id] == 2) res.push_back(root);

        return id;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<int, int>cnt;
        unordered_map<string, int>tripletToID;
        vector<TreeNode*>res;
        traverse(root, cnt,tripletToID, res);
        return res;
    }
};
