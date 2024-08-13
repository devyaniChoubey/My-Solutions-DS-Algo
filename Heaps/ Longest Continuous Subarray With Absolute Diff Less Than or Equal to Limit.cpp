https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/?envType=company&envId=google&favoriteSlug=google-six-months&difficulty=MEDIUM&status=TO_DO


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>>maxi;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > mini; 
        int n = nums.size();
        int ans = 0;
        int left = 0, right = 0;

        while(right < n){
            maxi.push({nums[right] , right});
            mini.push({nums[right] , right});
            while(maxi.top().first - mini.top().first > limit){
                left++;

                while(maxi.top().second < left){
                    maxi.pop();
                }

                while(mini.top().second < left){
                    mini.pop();
                }
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};