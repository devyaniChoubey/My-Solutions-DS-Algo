https://leetcode.com/problems/last-stone-weight-ii/description/


// Same problem as:
// Divide all numbers into two groups,
// what is the minimum difference between the sum of two groups.
// Now it's a easy classic knapsack problem.

stones array = [a, b , c, d];
For any sequence of operations, the algebra boils down to difference of two sums

For example,
(((a - b) - c) - d) = a - b - c - d = (a) - (b + c + d)
((d - (a - b) )- c) = d - a + b - c = (d + b) - (a + c)


//DP
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        sum = accumulate(stones.begin(), stones.end(), sum);

        int ans = 1e9;
        vector<vector<int>>dp(n+1, vector<int>((sum/2) + 1 , 0));
        for(int i=0;i <= n;i++){
            for(int j=0;j <= sum/2;j++){
                if(i == 0){
                    if(j == 0) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }else {
                    int take = 0;
                    if(stones[i-1] <= j) take = dp[i-1][j-stones[i-1]];
                    int notTake = dp[i-1][j];

                    dp[i][j] = take + notTake;
                }
                if(i == n){
                    if(dp[i][j]){
                        ans = min(ans, sum - 2*j);
                    }
                }
            }
        }

        return ans;
    }
};