https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

TreeNode* sortedArrayBST(int low, int high, const vector<int> &nums){
    if(low > high) return NULL;

    int mid = (low+high)/2;

    TreeNode* node = new TreeNode(nums[mid]);

    node->left = sortedArrayBST(low, mid-1, nums);
    node->right = sortedArrayBST(mid+1, high, nums);

    return node;
}
TreeNode* Solution::sortedArrayToBST(const vector<int>& nums) {
    return sortedArrayBST(0, nums.size() - 1, nums);
}