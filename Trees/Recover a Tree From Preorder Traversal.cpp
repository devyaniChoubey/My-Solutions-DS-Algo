https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/?envType=daily-question&envId=2025-02-22

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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>>st;

        int n = traversal.size();
        int numPos = 0;
        int lastD = 0;
        int curNum = 0;
        int numLen = 0;

        int p=0;

        while(p < n-1 && traversal[p] != '-' && traversal[p+1] != '-'){
            curNum = curNum*10 + (traversal[p]-'0');
            p++;
        }

        curNum = curNum*10 + (traversal[p]-'0');
        numPos =  p;
        p++;

        TreeNode* root = new TreeNode(curNum);
        st.push({root, 0});
        
        curNum = 0;
        numLen = 0;

        for(int i=p;i < n;i++){
            if(traversal[i] == '-'){
                continue;
            }else {
                if(i < n-1 && traversal[i] != '-' && traversal[i+1] != '-'){
                    curNum = curNum*10 + (traversal[i]-'0');
                    numLen++;
                    continue;
                }

                curNum = curNum*10 + (traversal[i]-'0');
                numLen++;

                int curD = i - numPos - numLen;

                if(curD == lastD){
                    st.pop();
                    TreeNode* node = st.top().first;
                    int nodeVal = curNum;
                    node->right = new TreeNode(nodeVal);
                    st.push({node->right, curD});
                }else if(curD < lastD){
                    while(!st.empty() && st.top().second >= curD){
                        st.pop();
                    }

                    if(!st.empty()){
                        TreeNode* node = st.top().first;
                        st.pop();
                        int nodeVal = curNum;
                        node->right = new TreeNode(nodeVal);
                        st.push({node->right, curD});
                    }
                }else {
                    TreeNode* node = st.top().first;
                    int nodeVal = curNum;
                    node->left = new TreeNode(nodeVal);
                    st.push({node->left, curD});
                }

                lastD = curD;
                numPos =  i;
                curNum = 0;
                numLen = 0;

            }

        }

        return root;
    }
};