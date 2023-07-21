https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point

Nodes on whose removal graph breaks into multiple components

time[] -> store the time of insertion during dfs

low[] -> minimum of all adjacent nodes apart from parent and visited nodes

class Solution {
  public:
  int timer = 0;
  void  dfs(int node, int parent, int tim[], int low[], vector<int> &vis,vector<int> &artPoint, vector<int>adj[]){
      vis[node] = 1;
      tim[node] = low[node] = timer;
      timer++;
      int child = 0;
      for(auto it:adj[node]){
          if(it == parent) continue;
          if(vis[it] == 0){
              dfs(it, node, tim, low, vis,artPoint, adj);
              low[node] = min(low[node], low[it]);
              if(low[it] >= tim[node] && parent != -1){
                artPoint[node] = 1; 
              }
              child++;
          }else{
              low[node] = min(low[node], tim[it]);
          }
      }
      
      if(child > 1 && parent == -1)artPoint[node] = 1;
      
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>vis(V, 0);
        int tim[V];
        int low[V];
        vector<int>artPoint(V, 0);
        
        for(int i=0;i < V;i++){
            if(!vis[i]){
                dfs(i, -1, tim, low, vis,artPoint, adj);
            }
        }
        
        
        vector<int>ans;
        for(int i=0;i < V;i++){
            if(artPoint[i]){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) return {-1};
        
        return ans;
        
    }
};