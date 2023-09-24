https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;

        if(root == NULL) return ans;

        queue<Node*>q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            
            vector<int>level;
            for(int i=0;i < size;i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);

                for(int i=0;i < node->children.size();i++){
                    q.push(node->children[i]);
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};