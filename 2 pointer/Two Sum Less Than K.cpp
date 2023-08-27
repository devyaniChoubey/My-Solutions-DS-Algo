https://leetcode.com/problems/two-sum-less-than-k/description/

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0, r = n - 1;
        int ans = 0;

        while(l < r){
            if(nums[l] + nums[r] >= k) r--;
            else if(nums[l] + nums[r] < k){
                ans = max(nums[l] + nums[r], ans);
                l++;
            }
        }
        
        if(ans == 0) return -1;
        return ans;
    }
};