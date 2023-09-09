https://leetcode.com/problems/find-root-of-n-ary-tree/description/


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
    Node* findRoot(vector<Node*> tree) {
        unordered_map<Node*, bool>seen;

        for(auto node:tree){
            for(auto child:node->children){
                seen[child] = true;
            }
        }

        for(auto node:tree){
            if(!seen[node]) return node;
        }

        return NULL;
    }
};





//XOR 

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
    Node* findRoot(vector<Node*> tree) {
        int total_sum = 0;

        for(auto node:tree){
            total_sum ^= node->val;
            for(auto child:node->children){
                total_sum ^= child->val;
            }
        }

        for(auto node:tree){
            if(total_sum == node->val) return node;
        }

        return NULL;
    }
};