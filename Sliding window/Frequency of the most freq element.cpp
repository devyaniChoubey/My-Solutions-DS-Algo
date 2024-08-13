https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long left = 0, right = 0;
        long n = nums.size();
        long sum = 0;

        sort(nums.begin() , nums.end());

        long ans = 0;

        while(right < n){
            sum += nums[right];
            
            while(nums[right]*(right - left+1) - sum > k){
                sum -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;


    }
};