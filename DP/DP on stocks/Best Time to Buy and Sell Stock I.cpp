https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 1e9;
        int ans = 0;
        for(int i=0;i < prices.size();i++){
            if(i > 0){
                ans = max(ans , prices[i] - mini);
            }
            mini = min(prices[i], mini);
        }
        return ans;
    }
};