https://leetcode.com/problems/largest-divisible-subset/submissions/982036295/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1), hash(n);
        sort(nums.begin(), nums.end());
        int maxi = 0;
        int maxInd = 0; 
        for(int ind=0;ind < n;ind++){
            hash[ind] = ind;
            for(int prev=0;prev<ind;prev++){
                if(nums[ind] % nums[prev] == 0){
                    if(dp[ind] < 1 + dp[prev]){
                        hash[ind] = prev;
                        dp[ind] = 1 + dp[prev];
                    }
                }
            }
            if(maxi < dp[ind]){
                maxi = dp[ind];
                maxInd = ind;
            }
        }

        vector<int>ans;
        int i = maxInd;
        while(hash[i] != i){
            ans.push_back(nums[i]);
            i = hash[i];
        }
        ans.push_back(nums[i]);
        return ans;
    }
};