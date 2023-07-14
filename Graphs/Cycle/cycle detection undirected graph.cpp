https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//using bfs

bool bfsIsCycle(int ver, vector<int>vis, vector<int> adj[]){
    queue<pair<int,int>>q;
    q.push({ver, -1});
    vis[ver] = 1;
    
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push({it, node});
                vis[it] = 1;
            }else{
                if(it != par){
                    return true;
                }
            }
            
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    vector<int>vis(V+1, 0);
    
    for(int ver=0;ver < V;ver++){
        if(!vis[ver]){
            if(bfsIsCycle(ver, vis, adj)) return true;
        }
    }
    
    return false;
}


//using dfs

class Solution {
  public:
    // Function to detect cycle in an undirected graph.

    bool dfsIsCycle(int ver, int par, vector<int>vis, vector<int> adj[]){
        vis[ver] = 1;
        for(auto it: adj[ver]){
            if(!vis[it]){
                if(dfsIsCycle(it, ver, vis, adj)){
                    return true;
                }
            }else{
                if(it != par) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V+1, 0);
        
        for(int ver=0;ver < V;ver++){
            if(!vis[ver]){
                if(dfsIsCycle(ver, -1, vis,adj)){
                    return true;
                }
            }
        }
        
        return false;
    }
};