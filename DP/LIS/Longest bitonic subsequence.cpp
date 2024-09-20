https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?leftPanelTab=1

https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    
	    vector<int>leftLIS(n, 1), rightLIS(n, 1);
	    
	    for(int ind=0;ind < n;ind++){
	        for(int prevInd=0;prevInd < ind;prevInd++){
	            if(nums[prevInd] < nums[ind]){
	                if(leftLIS[prevInd] + 1 > leftLIS[ind]){
	                    leftLIS[ind] = leftLIS[prevInd] + 1;
	                }
	            }
	        }
	    }
	    
	    int ans = -1e9;
	    
	    for(int ind=n-1;ind >= 0;ind--){
	        for(int prevInd=n-1;prevInd >= ind+1;prevInd--){
	            if(nums[prevInd] < nums[ind]){
	                if(rightLIS[prevInd] + 1 > rightLIS[ind]){
	                    rightLIS[ind] = rightLIS[prevInd] + 1;
	                }
	            }
	        }
	        
	        ans = max(ans, rightLIS[ind] + leftLIS[ind] - 1);
	        
	    }
	    
	    return ans;
	    
	    
	    
	}
};

//Solution 2

class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int>dp(n, 1), dpb(n, 1);
	    for(int i=0;i < n;i++){
	        for(int prev=0;prev < i;prev++){
	            if(nums[i] > nums[prev] && dp[i] < dp[prev] + 1){
	                dp[i] = dp[prev] + 1;
	            }
	        }
	    }
	    
	    for(int i=n-1;i>=0;i--){
	        for(int prev = n-1;prev > i;prev--){
	            if(nums[i] > nums[prev] && dpb[i] < dpb[prev] + 1){
	                dpb[i] = dpb[prev] + 1;
	            }
	        }
	    }
	    
	    int maxi = 1;
	    
	    for(int i=0;i < n;i++){
	        maxi = max(maxi, (dp[i] + dpb[i] - 1));
	    }
	    
	    return maxi;
	}
};