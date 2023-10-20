https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

vector<int> Solution::getRow(int k) {
    vector<int>ans(k+1), prev(k+1);
    prev[0] = 1;
    
    for(int i=0;i <= k;i++){
        for(int j=0;j < i+1;j++){
            if(j == 0 || j == i) ans[j] = 1;
            else{
                ans[j] = prev[j] + prev[j-1];
            }
        }
        prev = ans;
    }
    
    return ans;
}

//Method 2
vector<int> Solution::getRow(int n) {
    vector <int> ans;
    int c = 1;
    for (int i = 1; i <= n+1; i++) {
        ans.push_back(c);
        c = c*(n+1-i) / i;
    }
    return ans;
}