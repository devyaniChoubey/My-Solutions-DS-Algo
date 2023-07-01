// User function Template for C++

https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1



class Solution{
public:
    int solve(int i, int j , int arr[]){
        if(i >=j) return 0;
        
        int minAns = 1e9;
        for(int k=i;k <= j-1;k++){
            int val = solve(i, k, arr) + solve(k+1, j, arr) + arr[i-1]*arr[k]*arr[j];
            minAns = min(minAns, val);
        }
        return minAns;
    }
    int matrixMultiplication(int N, int arr[])
    {
        return solve(1, N-1, arr);
    }
};


//Memoised

class Solution{
public:
    int MCM(int arr[], int i , int j, int dp[101][101]){
         if(i >= j) return 0;
         int min = INT_MAX;
         if(dp[i][j] != -1) return dp[i][j];
         
         for(int k=i;k <= j-1;k++){
             int tempAns = MCM(arr, i, k, dp) + MCM(arr, k+1, j,dp) + arr[i-1]*arr[k]*arr[j];
             
             if(tempAns < min) min = tempAns;
         }
         
         return dp[i][j] = min;
         
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        return MCM(arr, 1 , N-1, dp);
    }
};


//Tabulation
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N+1, vector<int>(N+1, 0));
        
        for(int i=0;i < N;i++) dp[i][i] = 0;
        
        for(int i=N-1;i >= 1;i--){
            for(int j=i+1;j < N;j++){
                int minVal = 1e9;
                for(int k=i;k <= j-1;k++){
                    int val = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    minVal = min(val  , minVal);
                }
                dp[i][j] = minVal;
            }
        }
        //return solve(1, N-1, arr, dp);
        
        return dp[1][N-1];
    }

//MCM(i, j) return the min multiplication to multiply (matrix 1 ->  matrix 4)