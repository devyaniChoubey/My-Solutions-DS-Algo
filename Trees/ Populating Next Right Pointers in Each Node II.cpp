https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

//Method 1.1 level order traversal
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        queue<Node*>q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            
            for(int k=0;k < size;k++){
                Node* node = q.front();
                q.pop();

                if(k < size-1) node->next = q.front();

                if(node->left) q.push(node->left);
                
                if(node->right) q.push(node->right);
            }
        }

        return root;
    }
};

////Method 1.2 level order traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        queue<Node*>q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            
            Node* prevNode = NULL;
            for(int k=0;k < size;k++){
                Node* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    if(prevNode) prevNode->next = node->left;
                    prevNode = node->left;
                }

                if(node->right){
                    q.push(node->right);
                    if(prevNode) prevNode->next = node->right;
                    prevNode = node->right;
                }
            }
        }

        return root;
    }
};


//Space optimised

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        Node* leftMost = root;

        while(leftMost != NULL){
            Node* cur = leftMost;
            
            Node* prev = NULL;

            leftMost = NULL;
            while(cur != NULL){

                if(cur->left){
                    if(prev) prev->next = cur->left;
                    else leftMost = cur->left;

                    prev = cur->left;
                }

                if(cur->right){
                    if(prev) prev->next = cur->right;
                    else leftMost = cur->right;

                    prev = cur->right;
                }
                
                cur = cur->next;
            }
        }

        return root;
    }
};
