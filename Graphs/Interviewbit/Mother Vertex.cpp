https://www.interviewbit.com/problems/mother-vertex/

https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/

Do DFS traversal of the given graph. While doing traversal keep track of the last finished vertex ‘v’. This step takes O(V+E) time.
If there exists a mother vertex (or vertices), then v must be one (or one of them). Check if v is a mother vertex by doing DFS/BFS from v.
This step also takes O(V+E) time.


void dfs(int node, vector<int>&vis, vector<int>adj[]){
    vis[node] = 1;
    
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj);
        }
    }
}

int Solution::motherVertex(int A, vector<vector<int> > &B) {
    vector<int>adj[A+1];
    for(auto it:B) adj[it[0]].push_back(it[1]);
    vector<int>vis(A+1, 0);
    
    // To store last finished vertex (or mother vertex)
    int motherVertex;
    
    // Do a DFS traversal and find the last finished
    // vertex
    //last finished vertex
    for(int i=1;i <= A;i++){
        if(!vis[i]){
            dfs(i, vis, adj);
            motherVertex = i;
        }
    }

    // If there exist mother vertex (or vertices) in given
    // graph, then motherVertex must be one (or one of them)
 
    // Now check if motherVertex is actually a mother vertex (or graph
    // has a mother vertex).  We basically check if every
    // vertex is reachable from motherVertex or not.
 
    // Reset all values in visited[] as false and do
    // DFS beginning from motherVertex to check if all vertices are
    // reachable from it or not.
    
    fill(vis.begin(), vis.end(), 0);
    
    dfs(motherVertex, vis, adj);
    
    
    for(int i=1;i <= A;i++){
        if(!vis[i]) return false;
    }
    
    return true;
    
    
    
}
