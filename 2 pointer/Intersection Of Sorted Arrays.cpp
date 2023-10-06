https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int i =0, j = 0;
    int n1 = A.size();
    int n2 = B.size();
    
    vector<int> result;
    
    while(i < n1 && j < n2){
        if(A[i] < B[j]) i++;
        else if(A[i] > B[j]) j++;
        else{
            result.push_back(A[i]);
            i++;
            j++;
        }
    } 
    
    return result;
}
