
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

//arr 5 | 4 | 11 | 1 | 16 | 8
//dp  1 | 1 | 2 | 1 | 3 | 2

//dp[i] signifies length of LIS ending at index i
//par[i] stores index of previous element of LIS

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<int>dp(n+1, 1);
        int ans = 1;
        for(int ind=0;ind < n;ind++){
            for(int prevInd=0;prevInd < ind;prevInd++){
                if(nums[ind] > nums[prevInd]){
                    dp[ind] = max(dp[prevInd] + 1, dp[ind]);
                }
            }
            ans = max(ans, dp[ind]);
        }
        return ans;
    }
};



//Print LIS
https://www.codingninjas.com/studio/problems/printing-longest-increasing-subsequence_8360670?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here
	vector<int>dp(n+1, 1), par(n+1, 0);
	int maxInd = 0;
    for(int i=0;i < n;i++) par[i] = i;

	int ans = 1;
	for(int i=0;i < n;i++){
		for(int prev=0;prev < i;prev++){
			if(arr[i] > arr[prev]){
				if(dp[prev] + 1 > dp[i]){
                    par[i] = prev;
					dp[i] = dp[prev] + 1;
				}
			}
	    }
		if(ans < dp[i]){
            ans = dp[i];
			maxInd = i;
		}

	}
    
	vector<int>lis;
	

	int i=maxInd;
    while(par[i] != i){
	   lis.push_back(arr[i]);
       i = par[i];
	}
	lis.push_back(arr[i]);

	reverse(lis.begin(), lis.end());
	return lis;
}


      