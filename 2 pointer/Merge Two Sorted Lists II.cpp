https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    int m = B.size();
    
    int i = n - 1;
    int j = m - 1;
    
    int k = n + m - 1;
    
    A.resize(k+1);
    
    while(i >= 0 && j >= 0){
        if(A[i] < B[j]) {
            A[k] = B[j];
            j--;
        }else{
            A[k] = A[i];
            i--;
        }
        k--;
    }
    
    while(j >= 0){
        A[k] = B[j];
        j--;k--;
    }

}
