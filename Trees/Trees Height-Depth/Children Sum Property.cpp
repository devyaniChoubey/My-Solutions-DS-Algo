https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=30

void changeTree(TreeNode* root){
    if(root == NULL) return;

    int childSum = 0;
    if(root->left) childSum += root->left->val;
    if(root->right) childSum += root->right->val;

    if(childSum >= root->val) root->val = childSum;
    else {
        if(root->left) root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);

    int sum = 0;
    if(root->left) sum += root->left->val;
    if(root->right) sum += root->right->val;
    if(root->left || root->right) root->val = sum;

}