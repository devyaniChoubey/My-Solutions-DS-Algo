https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph


class Solution {
    public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<pair<int,int>>adj[n+1];
        vector<int>dist(n+1, 1e9);
        vector<int>par(n+1, 0);

        for(int i=0;i <= n;i++){
            par[i] = i;
        }

        for(int i=0;i < m;i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        //dist node
        set<pair<int,int>>st;
        dist[1] = 0;
        st.insert({0, 1});


        while(!st.empty()){
            auto it = *(st.begin());
            
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            for(auto it:adj[node]){
                int adjEdge = it.first;
                int edgWt = it.second;
                
                if(dist[adjEdge] > dist[node] + edgWt){
                    if(dist[adjEdge] != 1e9) st.erase({dist[adjEdge], adjEdge});
                    dist[adjEdge] = dist[node] + edgWt;
                    par[adjEdge] = node;
                    st.insert({dist[adjEdge], adjEdge});
                }
            }
            
        }

        vector<int>path;
        if(dist[n] == 1e9){
            return {-1};
        }

        //print path via backtracking
        int node = n;
        while(par[node] != node){
            path.push_back(node);
            node = par[node];
        }
        path.push_back(node);
        reverse(path.begin(), path.end());
        return path;

        
        
    }
}