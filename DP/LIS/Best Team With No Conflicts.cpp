/*
https://leetcode.com/problems/best-team-with-no-conflicts/

Actually, this problem is similar to find the maximum sum of increasing subsequence.

This problem want both age and score are increasing.
We can sort by age and do DP for scores.

Key points:
1) Create another arr by pair{age[i], socres[i]} and sorted by age.
2) Calculate max sum of LIS on the basis of scores on sorted array by age
*/


class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();

        // first: age;  second: scores
        vector<pair<int,int>>arr;
        for(int i=0;i < n;i++){
            arr.push_back({ages[i], scores[i]});
        }

        sort(arr.begin() , arr.end());

        vector<vector<int>>dp(n+1, vector<int>(n+2, 0));

        for(int i=n-1;i >= 0;i--){
            for(int j=i-1;j >= -1;j--){
                if((j == -1) || (arr[i].second >= arr[j].second)){
                    dp[i][j+1] = max(arr[i].second + dp[i+1][i+1] , dp[i+1][j+1]);
                }else dp[i][j+1] = dp[i+1][j+1];
            }
        }

        return dp[0][0];
    }
};