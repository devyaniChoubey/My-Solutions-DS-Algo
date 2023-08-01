

int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int low = INT_MAX, high = INT_MIN;
    for(int i=0;i < n;i++){
        low = min(low, A[i][0]);
        high = max(high, A[i][m-1]);
    }
    
    int desired = (n*m + 1)/2;
    
    while(low <= high){
        int mid = (low+high)/2;
        int cnt = 0;
        for(int i=0;i < n;i++){
            cnt += upper_bound(A[i].begin() , A[i].end() , mid) - A[i].begin();
        }
        
        
        if(cnt >= desired){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    
    return low;
}
