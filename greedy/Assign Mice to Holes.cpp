https://www.interviewbit.com/problems/assign-mice-to-holes/

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin() , A.end());
    sort(B.begin() , B.end());
    
    int minTime = -1e9;
    
    for(int i=0;i < A.size();i++){
        minTime = max(minTime, abs(A[i] - B[i]));
    }
    
    return minTime;
}
