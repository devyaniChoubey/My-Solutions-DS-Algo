https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfsCycle(int node, vector<int>&vis, vector<int>&pathVis, vector<int> adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfsCycle(it, vis,pathVis, adj)){
                    return true;
                }
            }else if(pathVis[it] == 1 && vis[it] == 1) return true;
        }
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V, 0);
        vector<int>pathVis(V, 0);
        
        for(int i=0;i < V; i++){
            if(!vis[i]){
                if(dfsCycle(i, vis, pathVis, adj)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
