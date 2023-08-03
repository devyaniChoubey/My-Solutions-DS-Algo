https://www.codingninjas.com/studio/problems/chocolate-pickup_3125885?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
int collectChocolates(int i, int j1, int j2,int n, int m, vector<vector<int>> &grid){
    if(j1 < 0 || j2 < 0 || j1 > m-1 || j2 > m-1) return -1e8;
    if(i == n-1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= +1;dj1++){
        for(int dj2 = -1; dj2 <= +1;dj2++){
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];

            maxi = max(maxi, value + collectChocolates(i+1, j1+dj1, j2+dj2,n,m, grid));
        }
    }

    return maxi;
}
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    return collectChocolates(0, 0, m-1,n,m, grid);
}



//Memoised

#include <bits/stdc++.h> 
int collectChocolates(int i, int j1, int j2,int n, int m, vector<vector<int>> &grid,vector<vector<vector<int>>>&dp){
    if(j1 < 0 || j2 < 0 || j1 > m-1 || j2 > m-1) return -1e8;
    if(i == n-1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= +1;dj1++){
        for(int dj2 = -1; dj2 <= +1;dj2++){
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];

            maxi = max(maxi, value + collectChocolates(i+1, j1+dj1, j2+dj2,n,m, grid,dp));
        }
    }

    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(m , vector<int>(m, -1)));
    return collectChocolates(0, 0, m-1,n,m, grid, dp);
}


//DP

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(m , vector<int>(m, 0)));
    
    for(int i=n-1;i >= 0;i--){
        for(int j1=m-1;j1 >= 0;j1--){
            for(int j2=m-1;j2 >= 0;j2--){
                if(i == n-1){
                    if(j1 == j2) dp[i][j1][j2] = grid[i][j1];
                    else dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                }else{
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++){
                        for(int dj2 = -1; dj2 <= 1; dj2++){
                            if(j1+dj1 < 0 || j1+dj1 > m-1 || j2+dj2 < 0 || j2+dj2 > m-1) continue;
                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else  value = grid[i][j1] + grid[i][j2];

                            maxi = max(maxi, value + dp[i+1][j1+dj1][j2+dj2]);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                } 
            } 
        } 
    }

    return dp[0][0][m-1];
}


//Space optimised

#include <bits/stdc++.h> 

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {   
    vector<vector<int>>prev(m , vector<int>(m, 0));
    vector<vector<int>>cur(m , vector<int>(m, 0));
    for(int i=n-1;i >= 0;i--){
        for(int j1=m-1;j1 >= 0;j1--){
            for(int j2=m-1;j2 >= 0;j2--){
                if(i == n-1){
                    if(j1 == j2) cur[j1][j2] = grid[i][j1];
                    else cur[j1][j2] = grid[i][j1] + grid[i][j2];
                }else{
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++){
                        for(int dj2 = -1; dj2 <= 1; dj2++){
                            if(j1+dj1 < 0 || j1+dj1 > m-1 || j2+dj2 < 0 || j2+dj2 > m-1) continue;
                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else  value = grid[i][j1] + grid[i][j2];

                            maxi = max(maxi, value + prev[j1+dj1][j2+dj2]);
                        }
                    }

                    cur[j1][j2] = maxi;
                } 
            } 
        } 
        prev =cur;
    }

    return cur[0][m-1];
}