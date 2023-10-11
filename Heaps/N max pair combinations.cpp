https://www.interviewbit.com/problems/n-max-pair-combinations/

https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<pair<int, pair<int,int>>>pq;
    set<pair<int,int>>st;
    
    sort(A.begin() , A.end());
    sort(B.begin() , B.end());
    
    int n = A.size();
    
    
    pq.push({A[n-1] + B[n-1] , {n-1, n-1}});
    st.insert({n-1, n-1});
    
    int k = n;
    
    vector<int>res;
    
    while(k--){
        int sum = pq.top().first;
        int i1 = pq.top().second.first;
        int i2 = pq.top().second.second;
        pq.pop();
        
        res.push_back(sum);
        
        if(i1 >= 0 && i2 > 0 && st.find({i1, i2 - 1}) == st.end()){
            pq.push({A[i1] + B[i2 - 1] , {i1, i2 - 1}});
            st.insert({i1, i2 - 1});
        }
        
        if(i1 > 0 && i2 >= 0 && st.find({i1-1, i2}) == st.end()){
            pq.push({A[i1-1] + B[i2] , {i1-1, i2}});
            st.insert({i1-1, i2});
        }
        
    }
    
    return res;
}
