https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph

class Solution {
  public:

    //store topo sort in stack
    void dfs(int node, vector<int>&vis, stack<int>&s, vector<pair<int,int>>adj[]){
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it.first]){
                dfs(it.first, vis,s, adj);
            }
        }
        
        s.push(node);
    }


    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(int i=0;i < M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        
        vector<int>vis(N, 0);
        stack<int>s;
        for(int i=0;i < N;i++){
            if(!vis[i]){
                dfs(i, vis,s, adj);
            }
        }
        
        
        vector<int>dist(N, 1e9);
        dist[0] = 0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            
            for(auto it:adj[node]){
                int edge = it.first;
                int wt = it.second;
                if(dist[edge] > dist[node] + wt){
                    dist[edge] = dist[node] + wt;
                }
            }
        }
        
        
        for(int i=0;i < N;i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
        
        
    }
};