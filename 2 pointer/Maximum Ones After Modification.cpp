https://www.interviewbit.com/problems/maximum-ones-after-modification/

int Solution::solve(vector<int> &nums, int k) {
    int left = 0, right = 0;
    int n = nums.size();
        
    while(right < n){
        if(nums[right] == 0) k--;
        
        if(k < 0){
            k += 1 - nums[left];
            left++;
        }
        
        right++;
    }
    
    return right-left;
}
