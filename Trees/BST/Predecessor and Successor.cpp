https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre = NULL, suc = NULL;
        Node* node = root;
        while(node != NULL){
            if(key >= node->key) node = node->right;
            else {
                suc = node;
                node = node->left;
            }
        }
        
        node = root;
        while(node != NULL){
            if(key <= node->key){
                node = node->left;
            } else {
                pre = node;
                node = node->right;
            }
        }
    }
};