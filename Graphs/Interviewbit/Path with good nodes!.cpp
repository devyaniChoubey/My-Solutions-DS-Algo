
https://www.interviewbit.com/problems/path-with-good-nodes/

void dfs(int node,int par,int goodNodeCnt, vector<int> &A, vector<int>adj[], int C, int &totalPath){
   
    if(A[node-1]) goodNodeCnt++;
    
    int childCnt = 0;
    for(auto it:adj[node]){
        if(it != par){
            childCnt++;
            dfs(it, node, goodNodeCnt, A, adj, C, totalPath);
        }
    }
    if(childCnt == 0 && goodNodeCnt <= C){
        totalPath++;
    }

}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {

    int n = A.size();
    vector<int>adj[n+1];
    
    for(int i=0;i < B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    
    int totalPath = 0;
    int goodNodeCnt = 0;
    
    dfs(1,-1, goodNodeCnt, A, adj, C, totalPath);
    
    return totalPath;
}