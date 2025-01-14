https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/?envType=daily-question&envId=2024-12-23


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
    int swapsCurLevel(vector<int>&original){
        unordered_map<int,int>mp;

        vector<int>target = original;

        int swaps = 0;

        sort(target.begin(), target.end());

        for(int i=0;i < original.size();i++){
            mp[original[i]] = i;
        }

        for(int i=0;i < target.size();i++){
            if(target[i] != original[i]){
                swaps++;

                int orgPos = mp[target[i]];

                mp[original[i]] = orgPos;

                swap(original[orgPos], original[i]);

            }
        }

        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int minSwaps = 0;

        while(!q.empty()){
            int size = q.size();

            vector<int>cur;

            while(size--){
                TreeNode* node = q.front();
                q.pop();
                cur.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

            minSwaps += swapsCurLevel(cur);
        }

        return minSwaps;
    }
};