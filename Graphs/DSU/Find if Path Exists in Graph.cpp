https://leetcode.com/problems/find-if-path-exists-in-graph/description/

//DSU

class DisjointSet {
    public:
    vector<int>parent,size;
    DisjointSet(int n){
       parent.resize(n+1);
       size.resize(n+1, 1);
       for(int i=0;i <= n;i++) parent[i] = i;
    }


    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);

        for(auto it:edges){
            ds.unionBySize(it[0], it[1]);
        }

        if(ds.findUPar(source) == ds.findUPar(destination)) return true;
        return false;
    }
};


//DFS

class Solution {
public:
    void dfs(int node, int par, int destination,vector<int>&vis, vector<int>adj[], bool &isValidPath){
        vis[node] = 1;
        if(node == destination) isValidPath = true;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it, node, destination,vis, adj, isValidPath);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];

        vector<int>vis(n, 0);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        bool isValidPath = false;

        dfs(source, -1, destination,vis, adj, isValidPath);

        return isValidPath;
    }
};