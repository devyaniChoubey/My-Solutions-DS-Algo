https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

class DisjointSet {
    vector<int>parent, size, rank;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        
        for(int i=0;i <= n;i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = parent[ulp_v];
            size[ulp_v] += size[ulp_u];
        }else {
            parent[ulp_v] = parent[ulp_u];
            size[ulp_u] += size[ulp_v];
        }
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = parent[ulp_v];
        }else if(rank[ulp_v] < rank[ulp_u])  {
            parent[ulp_v] = parent[ulp_u];
        }else{
            parent[ulp_v] = parent[ulp_u];
            rank[ulp_u]++;
        }
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       //wt, u , v
       vector<pair<int, pair<int,int>>>edges;
       
       for(int i=0;i < V;i++){
           int node = i;
           for(auto it:adj[i]){
               int adjNode = it[0];
               int adjWt = it[1];
               edges.push_back({adjWt , {node, adjNode}});
           }
       }
       
       sort(edges.begin(), edges.end());
       
       DisjointSet ds(V);
       
       int sum =0;
       for(auto it:edges){
           int wt = it.first;
           int u = it.second.first;
           int v = it.second.second;
           
           if(ds.findUPar(u) != ds.findUPar(v)) sum += wt; 
           ds.unionBySize(u , v);
       }
       
       return sum;
       
       
    }
};