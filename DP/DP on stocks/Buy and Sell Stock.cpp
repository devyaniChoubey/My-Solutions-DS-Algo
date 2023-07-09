https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int mini = prices[0];
      int profit = -1e9;
      for(int i=0;i < prices.size();i++){
        profit = max(profit, prices[i]-mini);
        mini = min(mini, prices[i]);
      }
      return profit;
    }
};



https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices,vector<vector<int>>&dp){
      if(ind == prices.size()) return 0;
      int profit;
      if(dp[ind][buy] != -1) return dp[ind][buy];

      int canBuyNext = solve(ind+1, 1, prices,dp);
      int canNotBuyNext = solve(ind+1, 0, prices,dp);
      if(buy){
        profit = max((-prices[ind] + canNotBuyNext), (0 + canBuyNext));
      }else{
        profit = max((+prices[ind] + canBuyNext),(0 + canNotBuyNext));
      }

      return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int prevCanBuyNext = 0;
      int prevCanNotBuyNext = 0;
      for(int ind = n-1;ind >= 0;ind--){
        int curCanBuyNext, curCanNotBuyNext;
        for(int buy=0; buy <= 1; buy++){
          if(buy){
            curCanBuyNext = max(-prices[ind] +prevCanNotBuyNext , 0 + prevCanBuyNext);
          }else{
            curCanNotBuyNext = max(prices[ind] + prevCanBuyNext , 0 + prevCanNotBuyNext);
          }
        }
        prevCanBuyNext = curCanBuyNext;
        prevCanNotBuyNext = curCanNotBuyNext;
      }
      return prevCanBuyNext;
    }
};


https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    int solve(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>&dp){
      int n = prices.size();
      if(ind == n) return 0;
      if(cap == 0) return 0;

      if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
      int profit;
      if(buy){
        profit = max(-prices[ind] + solve(ind+1, 0, cap, prices, dp), 0 + solve(ind+1, 1, cap, prices,dp));
      }else{
        profit = max(prices[ind] + solve(ind+1, 1, cap-1, prices,dp), 0 + solve(ind+1, 0, cap, prices,dp));
      }

      return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(3, 0)));
      
      vector<vector<int>>prev(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));
      for(int ind=n-1;ind >= 0;ind--){
        for(int buy=0;buy<=1;buy++){
          for(int cap=1;cap<=2;cap++){
            int profit;
            if(buy){
              profit = max(-prices[ind] + prev[0][cap] , 0 + prev[1][cap]);
            }else{
              profit = max(+prices[ind] + prev[1][cap-1] , 0 + prev[0][cap]);
            }
            cur[buy][cap] = profit;
          }
        }
        prev = cur;
      }

      return prev[1][2];
    }
};


https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:


  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<int>prev(2*k+1, 0),cur(2*k+1, 0);

    for(int ind=n-1;ind >= 0;ind--){
      for(int trans=(2*k-1);trans>=0;trans--){
        if(trans % 2 == 0){
          cur[trans] = max(-prices[ind] + prev[trans+1], prev[trans]);
        }else cur[trans] = max(+prices[ind] + prev[trans+1], prev[trans]);
      }
      prev = cur;
    }

    return prev[0];
    
  }
};


https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:

    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<int>front2(2, 0),front1(2, 0),cur(2, 0);

      for(int ind=n-1;ind >= 0;ind--){
        cur[1] = max(-prices[ind] + front1[0] , 0 + front1[1]);
        cur[0] =  max(+prices[ind] + front2[1] , 0 + front1[0]);

        front2 = front1;
        front1 = cur; 
      }

      return front1[1];
    }
};



https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
      int n = prices.size();
      vector<int>front(2, 0), cur(2, 0);

      for(int ind=n-1;ind>=0;ind--){
        cur[1] = max(-prices[ind] + front[0] , 0+front[1]);
        cur[0] = max(+prices[ind] + front[1]-fee , 0+front[0]);

        front = cur;
      }

      return cur[1];
    }
};