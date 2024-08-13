https://leetcode.com/problems/maximum-average-subarray-i/?envType=company&envId=google&favoriteSlug=google-six-months

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), right = 0, left = 0;
        double sum = 0, ans = -1e9;
        
        while(right < n){
            sum += nums[right];

            if(right >= k){
                sum -= nums[left];
                left++;
            }

            if(right >= k-1) ans = max(ans, sum/(double)k);

            
            right++;
        }

        return ans;
    }
};