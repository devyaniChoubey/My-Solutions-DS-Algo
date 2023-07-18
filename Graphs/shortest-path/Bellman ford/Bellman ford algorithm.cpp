applicable only in directed graph
helps to detect negative weight cycle
relax all the edges N-1 times sequentially (N no. of nodes)

relax means if(dist[u] + wt < dist[v]) dist[v] = dist[u] + wt

on Nth iteration if distance still decreases then there is a negative weight cycle


class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V, 1e8);
        dist[S] = 0;
        for(int i=0;i < V - 1;i++){
            for(int j=0;j < edges.size();j++){
                if(dist[edges[j][0]] != 1e8 && dist[edges[j][0]] + edges[j][2] < dist[edges[j][1]]){
                    dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
                }
            }
        }
        
        //Nth relaxation to check negative weight cycle
        for(int j=0;j < edges.size();j++){
            if(dist[edges[j][0]] != 1e8 && dist[edges[j][0]] + edges[j][2] < dist[edges[j][1]]){
                return {-1};
            }
        }
        
        return dist;
    }
};