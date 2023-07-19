https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph

// User function Template for C++

class DisjointSet {
    public:
    vector<int>parent, rank, size;
    DisjointSet(int n){
       parent.resize(n+1);
       rank.resize(n+1,0);
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

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u; 
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extraEdges = 0;
        for(int i=0;i < connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
             
            if(ds.findUPar(u) == ds.findUPar(v)){
                extraEdges++;
            }
            ds.unionBySize(u, v); 
        }

        int noOfComponents = 0;
        for(int i=0;i < n;i++){
            if(ds.findUPar(i) == i) noOfComponents++;
        }

        if(extraEdges >= noOfComponents - 1) return noOfComponents - 1;
        else return -1;
    }
};