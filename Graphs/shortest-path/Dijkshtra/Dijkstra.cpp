https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V, 1e9);
        dist[S] = 0;
        
        //{dist, node}
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        pq.push({0, S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int edge = it[0];
                int edgWt = it[1];
                
                if(dist[edge] > dist[node] + edgWt){
                    dist[edge] = dist[node] + edgWt;
                    pq.push({dist[edge] , edge});
                }
                
            }
        }
        
        return dist;
        
        
    }
};