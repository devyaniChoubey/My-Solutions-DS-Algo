https://leetcode.com/problems/jump-game/description/

//Linear solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i=0;i < nums.size();i++){
            if(i > maxReach) return false;

            maxReach = max(maxReach, (i + nums[i]));
        }

        return true;
    }
};


//Recursive
class Solution {
public:
  int solve(int ind, vector<int>& nums){
    int n = nums.size();
    if(ind == n-1) return true;
    if(ind > n-1) return false;

    for(int k=(ind+1); k <= (ind + nums[ind]); k++){
      if(solve(k, nums)) return true;
    }

    return false;
  }
  bool canJump(vector<int>& nums) {
    return solve(0, nums);
  }
};


//Memoised
class Solution {
public:
  int solve(int ind, vector<int>& nums, vector<int>&dp){
    int n = nums.size();
    if(ind == n-1) return 1;
    if(ind > n-1) return 0;

    if(dp[ind] != -1) return dp[ind];

    for(int k=(ind+1); k <= (ind + nums[ind]); k++){
      if(solve(k, nums,dp)) return dp[ind] = 1;
    }

    return dp[ind] = 0;
  }
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n+1, -1);
    return solve(0, nums, dp);
  }
};


