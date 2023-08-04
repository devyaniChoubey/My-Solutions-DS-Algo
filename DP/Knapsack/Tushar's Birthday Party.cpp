https://www.interviewbit.com/problems/tushars-birthday-party/

Hint 1

As friends cannot share dishes, can we independently calculate the cost for each friend and add them up? 
If we calculate answer for each person independently, how different is this from the standard Knapsack problem?

Time for some Dynamic thinking!

Solution Approach

**Observations: **

As the friends cannot share dishes, we can calculate the cost for each of them independently and add all such costs. 
Now, the problem instance for every friend is reduced to standard KnapSack problem.




int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int maxCap = 0;
    for(auto it:A) maxCap = max(it, maxCap);
    int n = B.size();
    
    vector<vector<int>>dp(n+1, vector<int>(maxCap+1, 0));
    
    for(int i=0;i <= n;i++){
        for(int j=0;j <= maxCap;j++){
            if(j == 0) dp[i][j] = 0;
            else if(i == 0) dp[i][j] = 1e9;
            else{
                int take = 1e9;
                if(B[i-1] <= j) take = C[i-1] + dp[i][j-B[i-1]];
                int notTake = dp[i-1][j];
                
                dp[i][j] = min(take, notTake);
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i < A.size();i++){
        ans += dp[n][A[i]];
    }
    
    return ans;
    
}

