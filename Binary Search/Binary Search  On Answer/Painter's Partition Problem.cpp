https://www.interviewbit.com/problems/painters-partition-problem/


int paintersRequired(vector<int> &C, long long maxArea){
    int paintersCnt = 1;
    int curArea = 0;
    
    for(int i=0;i < C.size();i++){
        if(curArea + C[i] <= maxArea){
            curArea = curArea + C[i];
        }else{
            paintersCnt++;
            curArea = C[i];
        }
    }
    
    return paintersCnt;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long low = -1e9;
    long long high = 0;
    int mod = 1e7+3;
    
    for(auto it:C){
        if(low < it) low = it;
        high += it;
    }
    
    while(low <= high){
        int mid = (low+high)/2;
        
        if(paintersRequired(C, mid) > A){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    
    return (low*B)%mod;
}
