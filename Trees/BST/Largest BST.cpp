https://practice.geeksforgeeks.org/problems/largest-bst/1

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    vector<int>largestBST(Node *root){
        if(root == NULL) return {0, INT_MIN, INT_MAX};
        
        vector<int>left = largestBST(root->left);
        vector<int>right = largestBST(root->right);
        
        if(root->data > left[1] && root->data < right[2]){
            return {(1 + left[0] + right[0]) , max(right[1], root->data) , min(left[2], root->data)};
        }else{
            return {max(left[0], right[0]) , INT_MAX , INT_MIN};
        }
    }

    int largestBst(Node *root)
    {
    	//Your code here
    	
    	return largestBST(root)[0];
    	
    }
};





//Class Based

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue{
    public:
    int maxNode, minNode, maxSize;
    NodeValue(int maxSize, int maxNode, int minNode){
        this->maxSize = maxSize;
        this->maxNode = maxNode;
        this->minNode = minNode;
    }
};
class Solution{
    public:
    
    
    NodeValue largestBST(Node *root){
        //empty tree is 0 sized BST
        if(!root) return NodeValue(0,INT_MIN, INT_MAX);
        
        auto left = largestBST(root->left);
        auto right = largestBST(root->right);
        
        if(left.maxNode < root->data && root->data < right.minNode){
            return NodeValue((1 + left.maxSize + right.maxSize),  max(right.maxNode, root->data), min(left.minNode, root->data));
        }else{
            return NodeValue(max(left.maxSize, right.maxSize), INT_MAX, INT_MIN);
        }
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        return largestBST(root).maxSize;
    	//Your code here
    }
};