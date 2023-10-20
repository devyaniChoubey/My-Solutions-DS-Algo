https://www.interviewbit.com/problems/maximum-absolute-difference/

int Solution::maxArr(vector<int> &A) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
    
    for(int i=0;i < A.size();i++){
        max1 = max(max1 , A[i] + i);
        min1 = min(min1 , A[i] + i);
        
        max2 = max(max2 , -A[i] + i);
        min2 = min(min2 , -A[i] + i);
        
        max3 = max(max3 , A[i] - i);
        min3 = min(min3 , A[i] - i);
        
        max4 = max(max4 , -A[i] - i);
        min4 = min(min4 , -A[i] - i);
    }
    
    return max({max1-min1, max2-min2, max3-min3, max4-min4});
}
