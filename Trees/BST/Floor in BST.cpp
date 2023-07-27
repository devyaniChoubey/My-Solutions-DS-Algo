https://practice.geeksforgeeks.org/problems/floor-in-bst/1

int floor(Node* root, int x) {
    // Code here
    int floor = -1;
    while(root != NULL){
        if(root->data == x){
            floor = root->data;
            break;
        }else if(root->data > x){
            root = root->left;
        }else{
            floor = root->data;
            root = root->right;
        }
    }
    
    return floor;
}
