https://leetcode.com/problems/minimum-cost-for-tickets/
https://leetcode.com/problems/minimum-cost-for-tickets/editorial/


class Solution {
public:
    int solve(int ind, int passEndDate, vector<int>& costs, vector<int>& days,vector<vector<int>>&dp){

        if(ind >= days.size()) return 0;

        if(dp[ind][passEndDate+1] != -1) return dp[ind][passEndDate+1];
        
        if(days[ind] <= passEndDate) {
            return dp[ind][passEndDate+1] = solve(ind+1, passEndDate, costs, days, dp);
        }else{
            int cost = 1e9;

            int OneDayPassCost = costs[0] + solve(ind+1, days[ind], costs, days,dp);
            int SevenDayPassCost = costs[1] + solve(ind+1, days[ind] + 6, costs, days,dp);
            int ThirtyDaysPassCost = costs[2] + solve(ind+1, days[ind] + 29, costs, days,dp);

            cost = min({OneDayPassCost, SevenDayPassCost,ThirtyDaysPassCost});

            return dp[ind][passEndDate+1] = cost;
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>>dp(n , vector<int>(400, -1));
        return solve(0, -1, costs, days,dp);
    }
};


//way 2

class Solution {
public:
    int solve(int curDay, unordered_set<int>&isTravelNeeded, vector<int>& days, vector<int>& costs,vector<int>&dp){
        int n = days.size();

        if(curDay > days[n-1]) return 0;

        if(dp[curDay] != -1) return dp[curDay];

        if(!isTravelNeeded.count(curDay)){
            return dp[curDay] = solve(curDay+1, isTravelNeeded, days, costs,dp);
        }


        int oneDayPass = costs[0] + solve(curDay+1, isTravelNeeded, days, costs,dp);
        int sevenDayPass = costs[1] + solve(curDay+7, isTravelNeeded, days, costs,dp);
        int thirtyDayPass = costs[2] + solve(curDay+30, isTravelNeeded, days, costs,dp);

        return dp[curDay] = min({oneDayPass,sevenDayPass, thirtyDayPass});
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int>isTravelNeeded;

        vector<int>dp(366, -1);

        for(int &day:days) isTravelNeeded.insert(day);

        return solve(days[0], isTravelNeeded, days, costs,dp);
    }
};