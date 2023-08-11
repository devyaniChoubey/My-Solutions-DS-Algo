https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<int>inDegree(A+1, 0);
    
    for(auto it:C) inDegree[it]++;
    
    vector<int>adj[A+1];
    
    for(int i=0;i < B.size(); i++){
        adj[B[i]].push_back(C[i]);
    }
    
    queue<int>q;
    
    for(int i=1;i <= A;i++){
        if(inDegree[i] == 0) q.push(i);
    }
    
    int topoCnt = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoCnt++;
        
        for(auto it:adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0) q.push(it);
        }
    }
    
    if(topoCnt == A) return true;
    else return false;
    
    
}
