https://www.interviewbit.com/problems/counting-subarrays/

int Solution::solve(vector<int> &nums, int B) {
    int ans = 0;
    
    int left = 0, right = 0;
    
    int n = nums.size();
    
    int curSum = 0;
    
    while(right < n){
        curSum += nums[right];
        
        while(curSum >= B){
            curSum -= nums[left];
            left++;
        }
        
        ans += (right - left + 1);
        
        right++;
    }
    
    return ans;
}
