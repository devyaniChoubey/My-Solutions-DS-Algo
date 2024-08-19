https://leetcode.com/problems/knight-probability-in-chessboard/

class Solution {
public:
    double solve(int row, int col, vector<pair<int, int>> &directions, int n, int k, vector<vector<vector<double>>>&dp){    
        if(row < 0 || col < 0 || row >= n || col >= n) return 0;
        else if(k == 0 && row >= 0 && row < n && col >= 0 && col < n) return 1;
        else if(k == 0) return 0;

        if(dp[row][col][k] != -1) return dp[row][col][k];

        double rate = 0;

        for(int i=0;i < directions.size();i++){
            rate += 0.125*solve(row+directions[i].first , col + directions[i].second, directions, n, k-1,dp);
        }

        return dp[row][col][k] = rate;
    }

    double knightProbability(int n, int k, int row, int column) {
        
       vector<pair<int, int>> directions = {{-2, -1} , {-2, 1} , {-1, -2}, {-1, +2}, {1, -2}, {1, 2}, {2, -1} , {2, +1}};

       vector<vector<vector<double>>>dp(n+1, vector<vector<double>>(n+1, vector<double>(k+1, -1.00)));

       return solve(row, column, directions, n, k,dp);

    }
};