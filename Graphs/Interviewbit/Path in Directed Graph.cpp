https://www.interviewbit.com/problems/path-in-directed-graph/

void dfs(int node, vector<int>adj[], vector<int>&vis){
    vis[node] = 1;
    
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int>vis(A+1, 0);
    vector<int>adj[A+1];
    
    for(int i=0;i < B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    
    dfs(1, adj, vis);
    
    if(!vis[A]) return 0;
    else return 1;
}
