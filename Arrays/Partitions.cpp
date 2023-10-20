https://www.interviewbit.com/problems/partitions/

int Solution::solve(int n, vector<int> &B) {
    
    vector<int>pref(n,0);
    pref[0] = B[0];
    
    for(int i=1;i < n;i++) pref[i] = pref[i-1] + B[i];
    
    if(pref[n-1] % 3 != 0) return 0;
    
    int req = pref[n-1]/3;
    
    int cnt = 0, ans = 0;
    
    for(int i=0;i < n;i++){
        if(pref[i] == 2*req) ans += cnt;
        cnt += (pref[i] == req);
    }
    
    return ans;
}
