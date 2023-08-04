Let the sum of all the given elements be S. This problem can be reduced to a Knapsack problem where we have to fill a Knapsack of capacity (S/2) as fully as 
possible and using the minimum no. of elements. We will fill the Knapsack with the given elements. Sign of all the elements which come into the knapsack 
will be flipped. As sum of all the elements in the Knapsack will be as close to S/2 as possible, we are indirectly calculating minimum non-negative sum 
of all the elements after flipping the sign

https://www.interviewbit.com/problems/flip-array/

//Recursive
pair<int,int> fun(int n , int W, vector<int> A){
    if(n == 0 || W == 0) return {0, 0};
    
    if(A[n-1] <= W){
        int prevWt = fun(n-1, W, A).first;
        int prevItems = fun(n-1, W, A).second;
        
        int curWt = fun(n-1, W-A[n-1], A).first + A[n-1];
        int curItems = fun(n-1, W-A[n-1], A).second + 1;
        
        if((curWt > prevWt) || ((curWt == prevWt) && (curItems < prevItems))){
            return {curWt, curItems};
        }else return fun(n-1, W, A);
    }else{
        return fun(n-1, W, A);
    }
}
int Solution::solve(const vector<int> &A) {
    int sum = 0;
    int n = A.size();
    for(auto it:A) sum += it;
    //vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
    return fun(n, sum/2, A).second;
}



//DP

struct node {
    int items;
    int weight;
} dp[105][10005];

int Solution::solve(const vector<int> &A) {
    int sum = 0;
    int n = A.size();
    for(auto it:A) sum += it;
    for(int i=0;i <= n;i++){
        for(int j=0;j <= sum/2;j++){
            if(i == 0 || j == 0) dp[i][j] = {0,0};
            else{
                if(j < A[i-1]) dp[i][j] = dp[i-1][j];
                else{
                    int prevWeight = dp[i-1][j].weight;
                    int prevItems = dp[i-1][j].items;
                    int curWeight = dp[i-1][j-A[i-1]].weight + A[i-1];
                    int curItems = dp[i-1][j-A[i-1]].items + 1;
                    if((curWeight > prevWeight) || ((curWeight == prevWeight) && (curItems < prevItems))){
                        dp[i][j] = {curItems,curWeight};
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
    }
    return dp[n][sum/2].items;
}




