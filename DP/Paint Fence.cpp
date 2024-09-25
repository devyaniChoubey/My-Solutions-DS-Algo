https://leetcode.com/problems/paint-fence/

class Solution {
public:
    int solve(int n, int k,vector<int>&dp){
        if(n == 0) return 0;
        if(n == 1) return k;
        if(n == 2) return k*k;

        if(dp[n] != -1) return dp[n];

        //paint the fence with different color as previous fence
        int ways = 0;
        ways += (k-1)*solve(n-1,k,dp);

       //paint the fence with same color as previous fence

        ways += 1 * ((k-1)*solve(n-2,k,dp));

        return dp[n] = ways;
    }
    int numWays(int n, int k) {
        vector<int>dp(n+1, -1);
        return solve(n, k,dp);
    }
};