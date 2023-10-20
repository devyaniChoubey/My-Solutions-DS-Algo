https://www.interviewbit.com/problems/segregate-0s-and-1s-in-an-array/

vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    int left = 0, right = n-1;
    
    while(left < right){
        while(left < right && A[left] == 0) left++;
        while(left < right && A[right] == 1) right--;
        
        if(left < right){
            swap(A[left] , A[right]);
            left++;
            right--;
        }
    }
    
    return A;

}
