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
    bool solve(int ind, vector<int>& nums,vector<int>&dp){
        int n = nums.size();
        if(ind == nums.size()-1) return true;
        if(ind >= nums.size()) return false;

        if(dp[ind] != -1) return dp[ind];

        if(nums[ind] == 0) return dp[ind] = false;

        int maxPosition = min(ind + nums[ind] , n-1);

        for(int nextPosition=maxPosition;nextPosition >= ind+1;nextPosition--){
            if(solve(nextPosition, nums,dp)) return dp[ind] = true;
        }

        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(0, nums,dp);
    }
};

//Tabulation 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, 0);

        for(int position=n-1;position >= 0;position--){
            if(position == n-1) dp[position] = true;
            else {
                int maxPosition = min(position + nums[position] , n-1);

                int ans = false;
                for(int nextPosition=maxPosition;nextPosition >= position+1;nextPosition--){
                    ans = ans || dp[nextPosition];
                }
                dp[position] = ans;
            }
        }
        return dp[0];
    }
};


