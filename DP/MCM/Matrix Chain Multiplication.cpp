// User function Template for C++

https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. 
In other words, no matter how we parenthesize the product, the result will be the same. 
For example, if we had four matrices A, B, C, and D, we would have: 
(ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, 
or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,  
(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
Clearly the first parenthesization requires less number of operations.
Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i]. 
We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain. 
*/

class Solution{
public:
    int MCM(int i, int j, int arr[]){
        if(i >= j) return 0;
        
        int mini = 1e9;
        for(int k=i;k < j;k++){
            int leftCost = MCM(i, k,arr);
            int rightCost = MCM(k+1, j,arr);
            int multiplyCost = arr[i-1]*arr[k]*arr[j];
            int totalCost = leftCost + rightCost + multiplyCost;
            
            mini = min(totalCost, mini);
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return MCM(1, N-1, arr);
    }
};


//Memoised

class Solution{
public:
    int MCM(int i, int j, int arr[], vector<vector<int>>&dp){
        if(i >= j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k=i;k < j;k++){
            int leftCost = MCM(i, k,arr,dp);
            int rightCost = MCM(k+1, j,arr,dp);
            int multiplyCost = arr[i-1]*arr[k]*arr[j];
            int totalCost = leftCost + rightCost + multiplyCost;
            
            mini = min(totalCost, mini);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(N, -1));
        return MCM(1, N-1, arr, dp);
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