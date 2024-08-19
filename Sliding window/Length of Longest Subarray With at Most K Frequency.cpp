https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        unordered_map<int,int>freq;
        int ans = 0;

        while(right < n){
            freq[nums[right]]++;

            while(freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};