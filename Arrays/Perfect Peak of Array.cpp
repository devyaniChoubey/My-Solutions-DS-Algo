https://www.interviewbit.com/problems/perfect-peak-of-array/

int Solution::perfectPeak(vector<int> &A) {
    int n = A.size();
    
    vector<int>leftMax(n);
    vector<int>rightMin(n);
    
    leftMax[0] = A[0];
    
    for(int i=1;i < n;i++){
        leftMax[i] = max(leftMax[i-1] , A[i]);
    }
    
    rightMin[n-1] = A[n-1];
    
    for(int i=n-2;i >= 0;i--){
        rightMin[i] = min(rightMin[i+1] , A[i]);
    }
    
    for(int i=1;i < n-1;i++){
        if(leftMax[i-1] < A[i] && A[i] < rightMin[i+1]) return 1;
    }
    
    
    return 0;
}