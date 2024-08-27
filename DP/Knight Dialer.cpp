https://leetcode.com/problems/knight-dialer/

class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int number, vector<int>moves[], int len, vector<vector<int>>&dp){
        if(len == 0) return 1;

        if(dp[number][len] != -1) return dp[number][len];

        int cnt = 0;

        for(int x:moves[number]){
            cnt = (cnt + solve(x, moves, len-1, dp))%MOD;
        }

        return dp[number][len] = cnt%MOD;
    }
    int knightDialer(int n) {
        
        vector<int>moves[10] = {{4, 6} , {6, 8}, {7, 9} , {4,8}, {3, 9, 0} , {}, {1, 7, 0}, {2, 6} , {1, 3} , {4, 2}};

        int cnt = 0;

        vector<vector<int>>dp(10, vector<int>(n, -1));

        for(int i=0;i < 10;i++){
            cnt = (cnt + solve(i,moves, n-1,dp))%MOD;
        }
       
        return cnt;
    }
};