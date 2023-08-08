https://leetcode.com/problems/partition-array-for-maximum-sum/description/

class Solution {
public:
    int solve(int i, vector<int>& arr, int l){
        int n = arr.size();
        if(i == n) return 0;

        int ans = 0;int maxi = 0;
        for(int k=i;k < min((l+i), n);k++){
            maxi = max(maxi, arr[k]);
            int maxVal = maxi*(k-i+1) + solve(k+1, arr, l);
            ans = max(ans, maxVal);
        }

        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return solve(0, arr, k);
    }
};


//memoised

class Solution {
public:
    int solve(int i, vector<int>& arr, int l,vector<int>&dp){
        int n = arr.size();
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];
        int ans = 0;int maxi = 0;
        for(int k=i;k < min((l+i), n);k++){
            maxi = max(maxi, arr[k]);
            int maxVal = maxi*(k-i+1) + solve(k+1, arr, l,dp);
            ans = max(ans, maxVal);
        }

        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, -1);
        return solve(0, arr, k, dp);
    }
};


//DP

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int l) {
        int n = arr.size();
        vector<int>dp(n+1, 0);
        for(int i=n;i >= 0;i--){
            if(i == n) dp[i] = 0;
            else{
                int maxi = 0, ans = 0;
                for(int k=i;k < min((l+i), n); k++){
                   maxi = max(arr[k] , maxi);
                   int maxVal = (k-i+1)*maxi + dp[k+1];
                   ans = max(ans, maxVal);
                }
                dp[i] = ans;
            }
        }
        return dp[0];
    }
};