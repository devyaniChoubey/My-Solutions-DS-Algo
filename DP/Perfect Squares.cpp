https://leetcode.com/problems/perfect-squares/?envType=problem-list-v2&envId=55ac4kuc

class Solution {
public:
    bool isPerfectSquare(int n){
        long long sr = sqrt(n);

        if(sr*sr == n) return true;
        else return false;
    }

    int solve(int sum , vector<int>&prefectSquares, int n,vector<vector<int>>&dp){
        if(sum == 0) return 0;
        if(n <= 0) return 1e9;

        if(dp[sum][n] != -1) return dp[sum][n];

        
        int take = 1e9;
        if(sum >= prefectSquares[n-1]) take = 1 + solve(sum - prefectSquares[n-1] , prefectSquares, n,dp);
        int notTake = solve(sum, prefectSquares, n-1,dp);

        return dp[sum][n] = min(take, notTake);
    }
    int numSquares(int n) {
        vector<int>prefectSquares;

        for(int i=n;i >= 1;i--){
            if(isPerfectSquare(i)) {
                prefectSquares.push_back(i);
            }
        }

        int size = prefectSquares.size();

        vector<vector<int>>dp(n+1, vector<int>(size+1, -1));

        return solve(n, prefectSquares, size,dp);
    }
};