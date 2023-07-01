
//Recursive

class Solution {
public:
    int solve(int i, int j , vector<int>&cuts){
        if(i > j) return 0;

        int mini = 1e9;
        for(int k = i;k <= j;k++){
            int val = solve(i, k-1,cuts) + solve(k+1, j,cuts) + cuts[j+1] - cuts[i-1];
            mini = min(mini, val); 
        }

        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        return solve(1, c-2, cuts);
    }
}; 


//Memoisation

class Solution {
public:
    int solve(int i, int j , vector<int>&cuts, vector<vector<int>>&dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i;k <= j;k++){
            int val = solve(i, k-1,cuts, dp) + solve(k+1, j,cuts,dp) + cuts[j+1] - cuts[i-1];
            mini = min(mini, val); 
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(c , vector<int>(c, -1));
        return solve(1, c-2, cuts,dp);
    }
}; 

//Tabulation

class Solution {
public:
    int solve(int i, int j , vector<int>&cuts, vector<vector<int>>&dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i;k <= j;k++){
            int val = solve(i, k-1,cuts, dp) + solve(k+1, j,cuts,dp) + cuts[j+1] - cuts[i-1];
            mini = min(mini, val); 
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(c , vector<int>(c, 0));

        for(int i=c-2;i >= 1;i--){
            for(int j=i;j <= c-2;j++){
                int mini = 1e9;
                for(int k=i;k <= j;k++){
                    int val = dp[i][k-1] + dp[k+1][j] + cuts[j+1] - cuts[i-1];
                    mini = min(mini, val);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c-2];
    }
}; 