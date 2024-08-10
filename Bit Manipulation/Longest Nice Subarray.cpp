https://leetcode.com/problems/longest-nice-subarray/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int used = 0,left = 0,right = 0, ans = 0;

        while(right < nums.size()){
            while((used & nums[right]) != 0){
                used = used ^ nums[left];
                left++;
            }

            used = used | nums[right];

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};