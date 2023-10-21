https://www.interviewbit.com/problems/array-sum/


vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    int n1 = A.size(), n2 = B.size();
    
    int i1 = n1-1, i2 = n2-1;
    int carry = 0;
    vector<int>ans;
    
    while(i1 >= 0 || i2 >= 0 || carry == 1){
        int sum = 0;
        if(i1 >= 0){
            sum += A[i1--];
        }
        
        if(i2 >= 0){
            sum += B[i2--];
        }
        
        sum += carry;
        
        carry = sum/10;
        
        sum = sum%10;
        
        ans.push_back(sum);
    }
    
    reverse(ans.begin() , ans.end());
    
    return ans;
}
