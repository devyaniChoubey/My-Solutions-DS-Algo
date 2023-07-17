https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
      vector<int>adj[N];
      
      for(int i=0;i < M;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
      }
      
      vector<int>dist(N, 1e9);
      dist[src] = 0;
      
      queue<int>q;
      q.push(src);
      
      while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dist[it] == 1e9) q.push(it);
            if(dist[it] > dist[node] + 1){
                dist[it] = dist[node] + 1;
            }
        }
      }
      
      for(int i=0;i < N;i++){
        if(dist[i] == 1e9) dist[i] = -1;
      }
      
      return dist;
    }
};