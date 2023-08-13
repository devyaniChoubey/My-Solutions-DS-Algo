https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

int max_ans = 0;

int dfs(int node, vector<int>adj[]){
    int max1 = 0, max2 = 0;
    //max1 = maximum height of all childNodes
    //max2 = second maximum height of all childNodes
    
    int childNodesCnt = adj[node].size();
    if(childNodesCnt == 0) return 1;
    
    for(int i=0;i < childNodesCnt;i++){
        int ans = dfs(adj[node][i], adj);
        if(ans > max1){
            max2 = max1;
            max1 = ans;
        }else if(ans > max2){
            max2 = ans;
        }
    }
    max_ans = max(max_ans , (max1 + max2));
    return 1 + max(max1, max2);
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    if(n < 2) return 0;
    
    max_ans = 0;
    
    vector<int>adj[n];
    
    int root = -1;
    
    for(int i=0;i < n;i++){
        if(A[i] == -1){
            root = i;
            continue;
        }
        adj[A[i]].push_back(i);
    }
    
    dfs(root, adj);
    
    return max_ans;
}
