
https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/

int subarraysWithAtMostKOdd(vector<int> &nums, int k){
        if(k < 0) return 0;
        int left = 0, right = 0;
        int n = nums.size();
        int cnt = 0;
        
        int odds = 0;

        while(right < n){
            if(nums[right] % 2 != 0) odds++;

            while(odds > k){
               if(nums[left] % 2 != 0) odds--;
               left++;
            }

            cnt += right - left + 1;

            right++;
        }

        return cnt;
}

int Solution::solve(vector<int> &nums, int k) {
    return subarraysWithAtMostKOdd(nums, k) - subarraysWithAtMostKOdd(nums, k-1);
}
