https://leetcode.com/problems/filling-bookcase-shelves/?envType=company&envId=google&favoriteSlug=google-thirty-days&status=TO_DO

class Solution {
public:
    int solve(int ind, vector<vector<int>>& books, int shelfWidth,vector<int>&dp){
        if(ind == books.size()) return 0;
        
        int widthSum = 0;
        int heightMax = 0;
        int height = 1e9;

        if(dp[ind] != -1) return dp[ind];
        for(int i=ind;i < books.size();i++){
           widthSum += books[i][0];
           heightMax = max(heightMax, books[i][1]);
           if(widthSum <= shelfWidth) height = min(height, heightMax + solve(i+1, books, shelfWidth,dp));
        }

        return dp[ind] = height;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int>dp(books.size() , -1);
        return solve(0, books, shelfWidth,dp);
    }
};