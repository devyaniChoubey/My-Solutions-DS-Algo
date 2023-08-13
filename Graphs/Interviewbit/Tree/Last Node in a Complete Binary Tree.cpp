https://www.interviewbit.com/problems/last-node-in-a-complete-binary-tree/


// TC O(N)

int Solution::lastNode(TreeNode* A) {
    TreeNode* ansNode = NULL;
    
    queue<TreeNode*>q;
    q.push(A);
    
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        
        ansNode = node;
        
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    
    return ansNode->val;
}


So, the idea here is to compare the height of the two subtrees.
If the height of the left subtree is higher, we go left, else we go right.
We can find the height of a subtree in O(log N), and this will be repeated for O(log N) steps.

Therefore, we can find the answer in O(log N * log N).

//TC O(log N * log N)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findLeftH(TreeNode* A) {
    int height = 0;

    while (A != NULL) {
        A = A->left;
        height++;
    }

    return height;
}


int Solution::lastNode(TreeNode* A) {
    int h = findLeftH(A);

    if (h == 1) {
        return A->val;
    }

    if ((h-1) == findLeftH(A->right)) return lastNode(A->right);
    else return lastNode(A->left);
}