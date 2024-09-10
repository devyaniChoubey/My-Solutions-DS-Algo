https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*>seen;

        while(p != NULL){
            seen.insert(p);
            p = p->parent;
        }

        while(q != NULL){
            if(seen.count(q)) return q;
            q = q->parent;
        }

        return NULL;
    }
};