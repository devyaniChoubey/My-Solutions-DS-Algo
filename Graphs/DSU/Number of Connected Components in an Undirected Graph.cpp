https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

class DisjointSet {
    public: 
    vector<int>size, parent;

    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);

        for(int i=0;i < n;i++) parent[i] = i;
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
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        
        for(auto it:edges){
            if(ds.findUPar(it[0]) != ds.findUPar(it[1]))n--;
            ds.unionBySize(it[0], it[1]);
        }

        return n;

    }
};