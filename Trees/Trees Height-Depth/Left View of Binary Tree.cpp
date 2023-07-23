https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
 
void leftSideView(Node *root, vector<int>&ans, int level){
     if(root == NULL) return;
     
     if(level == ans.size()){
         ans.push_back(root->data);
     }
     
     leftSideView(root->left, ans, level+1);
     leftSideView(root->right, ans, level+1);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   
   int level = 0;
   vector<int>ans;
   leftSideView(root, ans, level);
   return ans;
}