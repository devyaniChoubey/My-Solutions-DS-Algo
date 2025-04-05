
https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/?envType=daily-question&envId=2025-04-03
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            vector<int>leftMax(n, 0), rightMax(n, 0);
            leftMax[0] = nums[0];
            rightMax[n-1] = nums[n-1];
    
            for(int i=1;i < n;i++){
                leftMax[i] = max(leftMax[i-1] , nums[i]);
                rightMax[n-1-i] = max(rightMax[n-i] , nums[n-1-i]);
            }
    
            long long ans = 0;
    
            for(int j=1;j < n-1;j++){
                ans = max(ans, (long long)(leftMax[j-1] - nums[j])* rightMax[j+1]);
            }
    
            return ans;
        }
    };