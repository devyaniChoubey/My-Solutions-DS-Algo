https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?leftPanelTab=1

https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

int longestBitonicSequence(vector<int>& nums,int n) {
        
    vector<int>dp(n, 1), dpb(n, 1);
    for(int ind=0;ind < n;ind++){
        for(int prev=0;prev < ind;prev++){
            if(nums[ind] > nums[prev] && dp[ind] < dp[prev] + 1){
                dp[ind] = dp[prev] + 1;
            }
        }
    }

    int maxi = 0;

    for(int ind=n-1;ind >= 0;ind--){
        for(int prev=n-1;prev > ind;prev--){
            if(nums[ind] > nums[prev] && dpb[ind] < dpb[prev] + 1){
                dpb[ind] = dpb[prev] + 1;
            }
        }
            maxi = max(maxi, dp[ind] + dpb[ind] - 1);
    }

    return maxi;
             
}



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