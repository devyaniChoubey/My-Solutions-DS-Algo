https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int arr_ptr = 0;
    	int dep_ptr = 0;
    	int platforms = 0;
    	
    	while(arr_ptr < n){
    	    if(arr[arr_ptr] <= dep[dep_ptr]) platforms++;
    	    else {
    	        dep_ptr++;
    	    }
    	    
    	    arr_ptr++;
    	}
    	
    	return platforms;
    }
};