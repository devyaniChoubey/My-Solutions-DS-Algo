https://leetcode.com/problems/solving-questions-with-brainpower/?envType=daily-question&envId=2025-04-01


class Solution {
    public:
        long long solve(int ind, vector<vector<int>>& questions,vector<long long>&dp){
            if(ind >= questions.size()) return 0;
    
            if(dp[ind] != -1) return dp[ind];
            long long pick = questions[ind][0] + solve(ind+questions[ind][1]+1, questions,dp);
    
            long long notpick = solve(ind+1, questions,dp);
    
            return dp[ind] = max(pick, notpick);
        }
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long>dp(n+1, -1);
            return solve(0, questions, dp);
        }
    };