https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1


vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    queue<int>q;
    q.push(0);
    vector<int>vis(V+1, 0);
    vis[0] = 1;
    vector<int>bfs;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(int i=0;i < adj[node].size();i++){
            
            if(!vis[adj[node][i]]){
                q.push(adj[node][i]);
                vis[adj[node][i]] = 1;
            }
        }
        
    }
    
    return bfs;
}