https://www.interviewbit.com/problems/painters-partition-problem/


long long NoOfPainters(vector<int> &arr, long long maxArea, long long n){
    long long noOfPainters = 1;
    long long area = 0;
    for(int i=0;i < n;i++){
        if(area+arr[i] > maxArea){
            noOfPainters++;
            area = arr[i];
        }else area += arr[i];
    }
    return noOfPainters;
}

int Solution::paint(int k, int B, vector<int> &arr) {
    // code here
    // return minimum time
    int n = arr.size();
    long long low = -1e9, high = 0;
    for(int i=0;i < n;i++){
        high += arr[i];
        if(arr[i] > low) low = arr[i];
    }
    
    while(low <= high){
        long long mid = (low+high)/2;
        
        if(NoOfPainters(arr, mid, n) > k){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return (low*B)%10000003;
}
