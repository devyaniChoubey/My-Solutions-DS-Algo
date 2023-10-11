https://www.interviewbit.com/problems/largest-permutation/

vector<int> Solution::solve(vector<int> &A, int B) {
    int i=0;
    
    int n = A.size();
    
    unordered_map<int,int>index;
    
    int _max = n;
    
    for(int i=0;i < n;i++) index[A[i]] = i;
    
    while(B > 0 && i < n){
        int j = index[_max];
        
        if(i != j){
            swap(A[i] , A[j]);
            index[A[i]] = i;
            index[A[j]] = j;
            B--;
        }
        
        i++;
        _max--;
    }
    
    return A;
}
