
https://www.interviewbit.com/problems/disjoint-intervals/

bool static compareEnd(const vector<int>&a, const vector<int>&b){
    return (a[1] < b[1]);
}
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin() , A.end() , compareEnd);
    
    int lastEnd = A[0][1];
    
    int cntDisjointIntervals = 1;
    
    for(int i=1;i < A.size();i++){
        if(A[i][0] > lastEnd){
            lastEnd = A[i][1];
            cntDisjointIntervals++;
        }
    }
    
    return cntDisjointIntervals;
}
