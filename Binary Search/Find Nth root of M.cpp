https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
        int low = 1, high = m;
        while(low <= high){
            int mid = (low+high)/2;
            if(pow(mid, n) == m) return mid;
            else if(pow(mid, n) > m){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
	}  
}; 


//Solution 2

class Solution{
	public:
	int findNthPower(int mid, int m, int n){
	    long long ans = 1;
	    for(int i=0;i < n;i++){
	        ans = ans*mid;
	       if(ans > m) return 2;
	    }
	    
	    if(ans < m) return 0;
	    if(ans == m){
	            return 1;
	    }
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	   int low = 1, high = m;
	   while(low <= high){
	       int mid = (low+high)/2;
	       
	       if(findNthPower(mid, m, n) == 1) return mid;
	       else if(findNthPower(mid, m, n) == 2) high = mid-1;
	       else low = mid+1;
	   }
	   
	   return -1;
	   
	}  
};