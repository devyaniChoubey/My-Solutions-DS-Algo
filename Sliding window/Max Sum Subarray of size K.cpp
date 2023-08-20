https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1


//TLE
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long maxSum = 0;
        for(int i=0;i < n-k+1;i++){
            long sum =0;
            for(int j=i;j < i+k;j++){
                sum += arr[j];
            }
            
            maxSum = max(sum , maxSum);
        }
        
        return maxSum;
    }
};


//Sliding window

class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long maxSum = 0;
        long sum = 0;
        
        for(int i=0;i < k;i++){
            sum += arr[i];
            maxSum = max(sum , maxSum);
        }
        
        for(int i=1;i < n-k+1;i++){
            sum = sum - arr[i-1] + arr[i+k-1];
            maxSum = max(sum , maxSum);
        }
        
        return maxSum;
    }
};

//Sliding window
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long maxSum = 0;
        long sum = 0;
        
        int i=0, j = 0;
        while(j < n){
            sum += arr[j];
            
            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k) {
                maxSum = max(maxSum, sum);
                sum -= arr[i];
                i++;
                j++;
            }
        }
        
        return maxSum;
    }
};