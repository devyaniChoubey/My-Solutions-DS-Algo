https://leetcode.com/problems/squares-of-a-sorted-array/description/

vector<int> Solution::solve(vector<int> &nums) {
    int n = nums.size();
    vector<int>ans(n);
    int left = 0, right = n-1;
    int square;
    
    for(int i=n-1;i >= 0;i--){
        if(abs(nums[left]) < abs(nums[right])){
            square = nums[right]*nums[right];
            right--;
        }else{
            square = nums[left]*nums[left];
            left++;
        }

        ans[i] = square;
    }

    return ans;
}
