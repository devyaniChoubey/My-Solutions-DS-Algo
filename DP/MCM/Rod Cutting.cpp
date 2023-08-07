https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

//Recursive

class Solution {
public:
    int solve(int i, int j, vector<int>& cuts){
        if(i > j) return 0;

        int mini = 1e9;
        for(int k=i;k <= j;k++){
            int leftCost = solve(i, k-1, cuts);
            int rightCost = solve(k+1, j, cuts);
            int cuttingCost = cuts[j+1] - cuts[i-1];
            int totalCost = leftCost + rightCost + cuttingCost;
           
            mini = min(totalCost, mini);
        } 

        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        n = cuts.size();
        return solve(1, n-2, cuts);
    }
};



//Memoised

class Solution {
public:
    int solve(int i, int j, vector<int>& cuts,vector<vector<int>>&dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k=i;k <= j;k++){
            int leftCost = solve(i, k-1, cuts, dp);
            int rightCost = solve(k+1, j, cuts,dp);
            int cuttingCost = cuts[j+1] - cuts[i-1];
            int totalCost = leftCost + rightCost + cuttingCost;
           
            mini = min(totalCost, mini);
        } 

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        n = cuts.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(1, n-2, cuts, dp);
    }
};