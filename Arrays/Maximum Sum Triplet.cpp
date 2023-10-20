https://www.interviewbit.com/problems/maximum-sum-triplet/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int>right(n);
    int mx = A[n-1];
    
    for(int i=n-2;i >= 0;i--){
        right[i] = mx;
        mx = max(A[i] , mx);
    }
    
    set<int>leftMax;
    
    leftMax.insert(A[0]);
    
    int maxTripletSum = 0;
    
    for(int i=1;i < n-1;i++){
        if(A[i] < right[i]){
            auto it = leftMax.lower_bound(A[i]);
            if(it != leftMax.begin()){
                it--;
                maxTripletSum = max(maxTripletSum, ((*it) + A[i] + right[i]));
            }
        }
        leftMax.insert(A[i]);
    }
    
    return maxTripletSum;

}
