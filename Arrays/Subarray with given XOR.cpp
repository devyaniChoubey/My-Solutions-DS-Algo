https://www.interviewbit.com/problems/subarray-with-given-xor/

[4, 2 , 2 , 6 , 4]

4,2,2,6 = xr

4 = x

2,2,6 = k

(x^k) = xr

(x^k)^k = xr^k

x = xr^k




int Solution::solve(vector<int> &A, int k) {
      
    int n = A.size();
    
    int res = 0;
    
    unordered_map<int , int>freq;
    
    int prefixXor = 0;
     
    for(int i=0;i < n;i++){
         
        prefixXor = prefixXor^A[i];
        
        if(prefixXor == k) res++;
        
        res += freq[prefixXor^k];
        
        freq[prefixXor]++;
    }
    
    return res;
}
