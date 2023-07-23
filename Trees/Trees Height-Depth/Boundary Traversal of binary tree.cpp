https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

bool isLeaf(Node *root){
    if(root->left == NULL && root->right == NULL) return true;
    return false;
}

void leafNodes(Node *root, vector<int>&ans){
    if(root == NULL) return;
    
    leafNodes(root->left, ans);
    if(isLeaf(root))ans.push_back(root->data);
    leafNodes(root->right, ans);
}

void leftBoundary(Node* root,vector<int>&ans){
    while(root != NULL){
        if(!isLeaf(root))ans.push_back(root->data);
        if(root->left) root = root->left;
        else root = root->right;
    }
}

void rightBoundary(Node* root,vector<int>&ans){
    vector<int>temp;
    while(root != NULL){
        if(!isLeaf(root))temp.push_back(root->data);
        if(root->right) root = root->right;
        else root = root->left;
    }
    for(int i=temp.size() - 1;i >= 0;i--){
        ans.push_back(temp[i]);
    }
    
}

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root != NULL && !isLeaf(root)) ans.push_back(root->data);
        leftBoundary(root->left, ans);
        leafNodes(root, ans);
        rightBoundary(root->right, ans);
        return ans;
    }
};