
https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1


// User function Template for C++

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    int ceil = -1;
    
    while(root != NULL){
        if(root->data == input){
            ceil = root->data;
            break;
        }else if(root->data > input){
            ceil = root->data;
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return ceil;

    // Your code here
}