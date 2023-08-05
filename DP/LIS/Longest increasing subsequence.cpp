
//Recursion
int solve(int ind, int prevInd, vector<int>&nums){
    int n = nums.size();
    if(ind == n) return 0;

    int len = 0 + solve(ind+1, prevInd, nums);
    if(prevInd == -1 || nums[ind] > nums[prevInd]){
        len = max(len, 1 + solve(ind+1, ind, nums));
    }

    return len;
}
int lengthOfLIS(vector<int>& nums) {
    return solve(0, -1, nums);
}  

//Recursion 2

class Solution {
public:
    int solve(int i, int prevIndex, vector<int>& nums){
        int n = nums.size();
        if(i >= n) return 0;

        int pick = -1;
        if((prevIndex == -1) || (nums[i] > nums[prevIndex])) pick = 1 + solve(i+1, i, nums);
        int notPick = solve(i+1, prevIndex, nums);

        return max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(0, -1, nums);
    }
};


//memoisation
class Solution {
public:
    int solve(int ind, int prevInd, vector<int>&nums,vector<vector<int>>&dp){
        int n = nums.size();
        if(ind >= n) return 0;

        if(dp[ind][prevInd+1] != -1)return dp[ind][prevInd+1];
        int len = 0 + solve(ind+1, prevInd, nums,dp);
        if(prevInd == -1 || nums[ind] > nums[prevInd]){
            len = max(len, 1 + solve(ind+1, ind, nums,dp));
        }

        return dp[ind][prevInd+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>>dp(n+1, vector<int>(n+2, -1));  
      return solve(0, -1, nums, dp);
    }
};


//tabulation

    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>>dp(n+1, vector<int>(n+2, 0)); 
      for(int ind=n-1;ind >= 0;ind--){
        for(int prevInd=ind-1;prevInd>=-1;prevInd--){
            if(prevInd == -1 || nums[ind] > nums[prevInd]){
                dp[ind][prevInd+1] = max(1 + dp[ind+1][ind+1], 0 + dp[ind+1][prevInd+1]);
            }else dp[ind][prevInd+1] = 0 + dp[ind+1][prevInd+1];
        }
      } 
      return dp[0][0];
    }


//Space Optimisation


    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<int>prev(n+1, 0),cur(n+1, 0); 
      for(int ind=n-1;ind >= 0;ind--){
        for(int prevInd=ind-1;prevInd>=-1;prevInd--){
            if(prevInd == -1 || nums[ind] > nums[prevInd]){
                cur[prevInd+1] = max(1 + prev[ind+1], 0 + prev[prevInd+1]);
            }else cur[prevInd+1] = 0 + prev[prevInd+1];
        }
        prev = cur;
      } 
      return cur[0];
    }

//Approach 2

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+1, 1);
        int maxi = 1;
        for(int i=0;i < nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1+dp[j]);
                    maxi = max(maxi, dp[i]);
                }
            }
        }

        return maxi;
    }
};



//arr 5 | 4 | 11 | 1 | 16 | 8
//dp  1 | 1 | 2 | 1 | 3 | 2

//dp[i] signifies length of LIS ending at index i
//hash[i] stores index of previous element of LIS


//Print LIS
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+1, 1), hash(nums.size() + 1);
        int maxi = 1;
        int maxIndex = 0;
        for(int i=0;i < nums.size();i++){
            hash[i] = i;
        }

        for(int i=0;i < nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1+dp[j]);
                    hash[i] = j;
                    if(dp[i] > maxi){
                        maxi = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }
        
        int i = maxIndex;
        while(hash[i] != i){
            cout << nums[i] << " ";
            i = hash[i];
        }
        cout << nums[i];

        return maxi;
    }
};


      