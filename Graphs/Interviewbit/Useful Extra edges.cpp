https://www.interviewbit.com/problems/useful-extra-edges/

// Use dijkstra 2 times. Once with C as origin and another
// with D as origin. Now for every node, you have the length of the shortest path from
// C and from D. Now you can just iterate over each road and check if this road 
// helps you decreasing the existing distance between C and D.
// whenever you get a better answer, you can update your answer to this
// value and keep iterating on the auxillary roads.

void dijkstra(int src, vector<pair<int,int>>adj[], vector<int>&dist){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, src}); // dist, node
    dist[src] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        
        for(auto it:adj[node]){
            if(dist[it.first] > dist[node] + it.second){
                dist[it.first] = dist[node] + it.second;
                pq.push({dist[it.first] , it.first });
            }
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B, int src, int destination, vector<vector<int> > &E) {
    vector<int>distS(A+1, 1e9); //to store distance of all nodes from Source
    vector<int>distD(A+1, 1e9); //to store distance of all nodes from Destination
    
    vector<pair<int,int>>adj[A+1], adjR[A+1];
    
    for(auto it:B){
        adj[it[0]].push_back({it[1], it[2]});
        adjR[it[1]].push_back({it[0], it[2]});
    }
    
    dijkstra(src, adj, distS);
    dijkstra(destination, adjR, distD);
    
    int ans = distS[destination];
    
    for(auto it:E){
        int u = it[0];
        int v = it[1];
        int d = it[2];
        
        ans = min(ans, min(distS[u] + distD[v] + d , distD[u] + distS[v] + d));
    }
    
    if(ans == 1e9) ans = -1;
    return ans;
}
